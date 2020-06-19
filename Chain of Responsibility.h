#pragma once
#include <iostream>
#include <string>
using namespace std;

class Picture
{
public:
    Picture(string str) : title(str)
    {
        cout << "Processing picture with title: " << title << endl;
    }

private:
    string title;
};

class PictureProcessor
{
    PictureProcessor* nextProcessor;

protected:
    virtual void processImplementation(Picture& pict) = 0;

public:
    PictureProcessor() : nextProcessor(0) { }

    void process(Picture& pic) {
        processImplementation(pic);
        if (nextProcessor != 0)
            nextProcessor->process(pic);
    }

    virtual ~PictureProcessor() { }

    void setNextProcessor(PictureProcessor* pr) {
        nextProcessor = pr;
    }
};

class Scale : public PictureProcessor
{
public:
    enum SCALE { S50, S100, S200, S300, S500 };
    Scale(SCALE s) : scale(s) { }

private:
    void processImplementation(Picture& pict) {
        cout << "Scaling photo" << endl;
    }

    SCALE scale;
};

class AddBokeh : public PictureProcessor
{
private:
    void processImplementation(Picture& pict) {
        cout << "Adding bokeh" << endl;
    }
};

class Filter : public PictureProcessor
{
private:
    void processImplementation(Picture& pict) {
        cout << "Applying filters" << endl;
    }
};

class ColorMatch : public PictureProcessor
{
private:
    void processImplementation(Picture& pict)
    {
        cout << "Matching colors" << endl;
    }
};

void processPicture(Picture& picture)
{
    ColorMatch match;
    AddBokeh bokeh;
    Filter filter;
    Scale scale(Scale::S200);
    scale.setNextProcessor(&bokeh);
    bokeh.setNextProcessor(&match);
    match.setNextProcessor(&filter);
    scale.process(picture);
}

