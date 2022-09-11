#include "MinesweeperWindow.h"
#include "Tile.h"

MinesweeperWindow::MinesweeperWindow(Point xy, int width, int height, int mines, const string& title):
	Graph_lib::Window{xy, width * cellSize, (height+1)* cellSize, title}, 
	width{width}, height{height}, mines{mines}, minesLeft{mines}, tilesLeft{height*width - mines},
	gameEndText{Point{Width()/3, Height()/2}, " " },
	minesLeftText{Point{Width()/3, Height()+18}, "Mines left: " + to_string(minesLeft)}
	//Initialiser medlemsvariabler, bruker konstruktoren til Windowsklassen
{
	// Legg til alle tiles i vinduet
	for (int i = 0; i < height; ++i) 
	{
		for (int j = 0; j < width; ++j) 
		{
			tiles.push_back(new Tile{ Point{j * cellSize, i * cellSize}, cellSize, cb_click});
			attach(tiles.back());
		}
	}

	int i = 0;
	while (i < this->mines)
	{
		int minePosition = rand() % tiles.size();
		if (tiles[minePosition].getMine() == false)
		{
			tiles[minePosition].setMine(true);
			++i;
		}
	}

	minesLeftText.set_color(Color::black);
	minesLeftText.set_font_size(15);
	attach(minesLeftText);

	// Fjern window reskalering
	resizable(nullptr);
	size_range(x_max(), y_max(), x_max(), y_max());
}

vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const 
{
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) 
	{
		for (int dj = -1; dj <= 1; ++dj) 
		{
			if (di == 0 && dj == 0) 
			{
				continue;
			}
			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) 
			{
				points.push_back(neighbour);
			}
		}
	}
	return points;
}

void MinesweeperWindow::openTile(Point xy) 
{
	Tile& t = at(xy);

	if (t.getState() != Cell::closed) 
	{
		return;
	}

	if (t.getMine())
	{
		gameLost();
		return;
	}

	t.open();
	tilesLeft --;

	vector<Point> point = adjacentPoints(xy);
	int mines = countMines(point);
	if (mines > 0)
	{
		t.setAdjMines(mines);
	}
	else 
	{
		for (Point p : point) 
		{
			openTile(p);
		}
	}
		
	if (tilesLeft == 0 && !gameIsWon)
	{
		gameWon();
		return;
	}
}

void MinesweeperWindow::flagTile(Point xy) 
{
	Tile& t = at(xy);
	t.flag();
	if (t.getState() == Cell::flagged)
	{
		minesLeft--;
		minesLeftText.set_label("Mines left: " + to_string(minesLeft));
		redraw();
	}
	else
	{
		minesLeft++;
		minesLeftText.set_label("Mines left: " + to_string(minesLeft));
		redraw();
	}
}

//Kaller openTile ved venstreklikk og flagTile ved hoyreklikk/trykke med to fingre paa mac
void MinesweeperWindow::click()
{
	Point xy{Fl::event_x(), Fl::event_y()};

	MouseButton mb = static_cast<MouseButton>(Fl::event_button());

	if (!inRange(xy)) {
		return;
	}
	switch (mb) {
	case MouseButton::left:
		openTile(xy);
		break;
	case MouseButton::right:
		flagTile(xy);
		break;
	}
	flush();
}

int MinesweeperWindow::countMines(vector<Point> coords) const
{	
	int mines = 0;
	for (Point p : coords)
	{
		if (at(p).getMine())
		{
			mines ++;
		}
	}
	return mines;
}

void MinesweeperWindow::gameLost()
{
	gameIsLost = true;
	for (Tile* tile : tiles) 
	{
		if (tile->getMine()) 
		{
			tile->open();
		}
	}
	addGameEndMenu("YOU LOST!");
}

void MinesweeperWindow::gameWon()
{
	gameIsWon = true;

	for (Tile* tile : tiles) 
	{
		if (tile->getState() == Cell::closed) {
			tile->flag();
		}
	}
	//Legg til meny for at spillet er vunnet
	addGameEndMenu("YOU WON!");
}

void MinesweeperWindow::addGameEndMenu(string s) {
	//sett riktig font og farger til vinn eller tap
	gameEndText.set_label(s);
	gameEndText.set_color(Color::red);
	gameEndText.set_font_size(20);

	//Legg til menyen pa vinduet
	attach(gameEndText);

	flush();
}