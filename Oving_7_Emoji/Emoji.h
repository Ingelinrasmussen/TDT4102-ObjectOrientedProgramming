#pragma once

// Include Graph_lib library files that holds declarations needed for Window,
// and Shape derivatives.
#include "Graph.h"
#include "GUI.h"

using namespace Graph_lib;

// An abstract class. Concrete classes derived from this base class
// has to implement the member function attach_to().
class Emoji{
public:
	// Disable copying. Disable slicing, etc.
	Emoji(const Emoji&) = delete;
	Emoji& operator=(const Emoji&) = delete;

	// Deleting the copy constructor also deletes the default constructor.
	// Emoji needs a default constructor.
	Emoji() {}
	// Emoji() = default; // is an alternative way of achieving the same.

	// The pure virtual function that has to be overriden for a deriving class
	// to be instantiable. Every class deriving from Emoji is supposed to
	// attach all its Shapes to a window. This makes the class abstract.
	virtual void attach_to(Graph_lib::Window&) = 0;

	// Relevant because Vector_ref can own Emojis and automatically cleans up.
	// Subject will be visited later in the course.
	virtual ~Emoji() {}
};

class Face: public Emoji{
private:
	Circle face;
public: 
	Face(const Face&) = delete;
	Face& operator=(const Face&) = delete;
	virtual ~Face() {}

	Face(Point c, int r);
	void attach_to(Graph_lib::Window& win) override = 0;
};

class EmptyFace : public Face{
public:
	EmptyFace(Point p, int r);
	void attach_to(Graph_lib::Window& win) override;
private:
	Circle leftEye;
	Circle rightEye;
};

class SmileyFace: public EmptyFace
{
public:
	SmileyFace(Point p, int r);
	virtual ~SmileyFace() {};
	void attach_to(Graph_lib::Window& win) override;
private:
	Arc Smiley;
};

class SadFace: public EmptyFace
{
public:
	SadFace(Point p, int r);
	virtual ~SadFace() {};
	void attach_to(Graph_lib::Window& win) override;
private:
	Arc Sad;
};

class AngryFace: public SadFace
{
public:
	AngryFace(Point p, int r);
	virtual ~AngryFace() {};
	void attach_to(Graph_lib::Window& win) override;
private:
	Arc Mouth;
	Arc LeftBrow;
	Arc RightBrow;
};

class WinkingFace: public Face
{
public:
	WinkingFace(Point p, int r);
	virtual ~WinkingFace() {};
	void attach_to(Graph_lib::Window& win) override;
private:
	Arc Mouth;
	Arc WinkingEye;
	Circle NormalEye;
};

class SurprisedFace: public EmptyFace
{
public:
	SurprisedFace(Point p, int r);
	virtual ~SurprisedFace() {};
	void attach_to(Graph_lib::Window& win) override;
private:
	Circle Mouth;
	Circle leftGlass;
	Circle rightGlass;
};