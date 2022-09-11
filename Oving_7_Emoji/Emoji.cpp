#include "Emoji.h"

Face::Face(Point c, int r) : face{c, r}
{
	face.set_fill_color(Color::yellow);
	face.set_color(Color::black);
}

void Face::attach_to(Graph_lib::Window& win)
{
	win.attach(face);
}

//p.x -r/2 er x-aksen til sentrum av øyet fra sntrum av fjest, p.y -r/8 er hvor langt opp fra y-aksen fra sentrum ab fjeset øyet skal være  
EmptyFace::EmptyFace(Point p, int r): 
Face(p,r), 
leftEye{Point{p.x - r/3, p.y - r/8}, r/9}, 
rightEye{Point{p.x + r/3, p.y - r/8}, r/9}
{

    leftEye.set_fill_color(Color::black);
	leftEye.set_color(Color::black);
    rightEye.set_fill_color(Color::black);
	rightEye.set_color(Color::black);

}

void EmptyFace::attach_to(Graph_lib::Window& win)
{
	Face::attach_to(win);
    win.attach(leftEye);
    win.attach(rightEye);

}

SmileyFace::SmileyFace(Point p, int r): 
EmptyFace{p, r}, 
Smiley{Point{p.x, p.y + r / 9}, int(5/3 * r), r, 190, 350}
{
	Smiley.set_color(Color::black);
	Smiley.set_style(Line_style(Line_style::solid, 4));
}

void SmileyFace::attach_to(Graph_lib::Window & win)
{
	EmptyFace::attach_to(win);
	win.attach(Smiley);
}

SadFace::SadFace(Point p, int r): 
EmptyFace{p, r}, Sad{Point{p.x, p.y + 3*r/4}, int(5/3 * r), r, 20, 160}
{
	Sad.set_color(Color::black);
	Sad.set_style(Line_style(Line_style::solid, 4));
}

void SadFace::attach_to(Graph_lib::Window & win)
{
	EmptyFace::attach_to(win);
	win.attach(Sad);
}


AngryFace::AngryFace(Point p, int r): 
SadFace{p, r}, 
Mouth{Point{p.x, p.y + 3*r/4}, 
int(5/3 * r), r, 20, 160}, LeftBrow{Point{p.x + 4*r/7, p.y - r/9}, 
int(5/3 * r), r, 140, 180}, RightBrow{Point{p.x - 4*r/7, p.y - r/9}, 
int(5/3 * r), r, 0, 40}
{
	Mouth.set_color(Color::black);
	Mouth.set_style(Line_style(Line_style::solid, 4));
	LeftBrow.set_color(Color::black);
	LeftBrow.set_style(Line_style(Line_style::solid, 4));
	RightBrow.set_color(Color::black);
	RightBrow.set_style(Line_style(Line_style::solid, 4));
}

void AngryFace::attach_to(Graph_lib::Window & win)
{
	EmptyFace::attach_to(win);
	win.attach(Mouth);
	win.attach(LeftBrow);
	win.attach(RightBrow);

}

WinkingFace::WinkingFace(Point p, int r): 
Face{p, r}, 
Mouth{Point{p.x, p.y + r / 9}, int(5/3 * r), r, 190, 350}, 
WinkingEye{Point{p.x + r/4, p.y - r / 9}, 
int(r/3), r/3, 0, 180}, 
NormalEye{Point{p.x - r/3, p.y - r/8}, r/9}
{
	Mouth.set_color(Color::black);
	Mouth.set_style(Line_style(Line_style::solid, 4));
	WinkingEye.set_color(Color::black);
	WinkingEye.set_style(Line_style(Line_style::solid, 4));
	NormalEye.set_fill_color(Color::black);
	NormalEye.set_color(Color::black);
}

void WinkingFace::attach_to(Graph_lib::Window & win)
{
	Face::attach_to(win);
	win.attach(Mouth);
	win.attach(WinkingEye);
	win.attach(NormalEye);
}

SurprisedFace::SurprisedFace(Point p, int r): 
EmptyFace{p, r}, Mouth{Point{p.x, p.y + 2*r/5}, r/5},
leftGlass{Point{p.x - r/3, p.y - r/8}, r/3}, 
rightGlass{Point{p.x + r/3, p.y - r/8}, r/3}
{	
	leftGlass.set_color(Color::black);
	rightGlass.set_color(Color::black);
    Mouth.set_fill_color(Color::white);
	Mouth.set_color(Color::black);
}

void SurprisedFace::attach_to(Graph_lib::Window & win)
{
	EmptyFace::attach_to(win);
	win.attach(Mouth);
	win.attach(leftGlass);
	win.attach(rightGlass);
}




