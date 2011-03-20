#include "SpriteMeta.h"

#include <CGE/Tools.h>
#include <rapidxml/rapidxml.hpp>

#include <iostream>
#include <fstream>
#include <map>
using namespace std;
using namespace rapidxml;

int getNumber(xml_attribute<>* inAttribute)
{
    if (!inAttribute) return 0;

    stringstream ss(inAttribute->value());
    int outNumber = 0;
    ss >> outNumber;
    return outNumber;
}

SpriteMeta::SpriteMeta(const char* inPath)
{
    if (!inPath)
    {
        cout << "invalid sprite path" << endl;
        return;
    }

    string path(inPath);
    path += "meta.xml";

    char* buffer = CGE::fileToBuffer(path.c_str());

    if (!buffer)
    {
        cout << "failed to open file " << path << endl;
        return;
    }

    xml_document<> doc;
    doc.parse<0>(buffer);

    free(buffer);

    map<string, size_t> regions;

    xml_node<>* root = doc.first_node("sprite");
    if (!root)
    {
        cout << "missing <sprite> tag" << endl;
        return;
    }

    for (xml_node<>* i = root->first_node("sheet"); i;
        i = i->next_sibling("sheet"))
    {
        xml_attribute<>* f = i->first_attribute("file");
        if (!f)
        {
            cout << "missing file attribute in <sheet>" << endl;
            continue;
        }

        for (xml_node<>* j = i->first_node("region"); j;
            j = j->next_sibling("region"))
        {
            xml_attribute<>* a = j->first_attribute("id");
            if (!a)
            {
                cout << "missing id attribute in <region>" << endl;
                continue;
            }

            string id(a->value());

            a = j->first_attribute("x");
            if (!a)
            {
                cout << "missing x (position) attribute in <region>" << endl;
                continue;
            }

            Region region;
            extractNumber(a->value(), region.x);

            a = j->first_attribute("y");
            if (!a)
            {
                cout << "missing y (position) attribute in <region>" << endl;
                continue;
            }

            extractNumber(a->value(), region.y);

            a = j->first_attribute("w");
            if (!a)
            {
                cout << "missing width attribute in <region>" << endl;
                continue;
            }

            extractNumber(a->value(), region.width);

            a = j->first_attribute("h");
            if (!a)
            {
                cout << "missing height attribute in <region>" << endl;
                continue;
            }

            extractNumber(a->value(), region.height);

            regions[id] = mRegions.size();
            mRegions.push_back(region);
        }
    }

    for (xml_node<>* i = root->first_node("animation"); i;
        i = i->next_sibling("animation"))
    {
        vector<Frame> frames;

        for (xml_node<>* j = i->first_node("frame"); j;
            j = j->next_sibling("frame"))
        {
            Frame frame;

            xml_attribute<>* a = j->first_attribute("duration");
            if (!a)
            {
                cout << "missing duration attribute in <frame>" << endl;
                continue;
            }

            extractNumber(a->value(), frame.duration);

            a = j->first_attribute("region");
            if (!a)
            {
                cout << "missing region attribute in <frame>" << endl;
                continue;
            }

            map<string, size_t>::iterator it = regions.find(a->value());

            if (it == regions.end())
            {
                cout << "region \"" << a->value() << "\" does not exist"
                    << endl;
                continue;
            }

            frame.index = it->second;

            frames.push_back(frame);
        }

        if (frames.size())
        {
            Animation animation;
            animation.frames = new Frame[frames.size()];
            animation.count = frames.size();
            memcpy(animation.frames, &frames[0], frames.size() * sizeof(Frame));
            mAnimations.push_back(animation);
        }
    }
}

SpriteMeta::~SpriteMeta()
{
    for (size_t i = 0; i < mAnimations.size(); ++i)
        delete [] mAnimations[i].frames;
}

SpriteMeta::Animation SpriteMeta::getAnimation(size_t inIndex) const
{
    return mAnimations[inIndex];
}
