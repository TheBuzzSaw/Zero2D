#include "Sprite.h"
#include "rapidxml/rapidxml.hpp"
#include <CGE/Heap.h>
#include <CGE/Tools.h>
#include <iostream>

using namespace rapidxml;
using namespace std;

static CGE::Heap SpriteHeap("Sprite");
static const char* const SheetNode = "sheet";
static const char* const RegionNode = "region";
static const char* const AnimationNode = "animation";
static const char* const FrameNode = "frame";

static const char* getAttribute(xml_node<>* inNode, const char* inAttribute)
{
    const char* outAttribute = NULL;

    if (inNode)
    {
        xml_attribute<>* attribute = inNode->first_attribute(inAttribute);

        if (attribute) outAttribute = attribute->value();
    }

    return outAttribute;
}

Sprite::Sprite(const char* inPath)
{
    string metaPath(inPath);
    metaPath += "meta.xml";

    char* content = CGE::fileToBuffer(metaPath.c_str());

    if (CGE::hasContent(content))
    {
        xml_document<> document;
        document.parse<0>(content);

        xml_node<>* root = document.first_node("sprite");

        if (root)
        {
            cout << "valid meta.xml file: " << root->name() << endl;

            for (xml_node<>* i = root->first_node(SheetNode); i;
                i = i->next_sibling(SheetNode))
            {
                const char* filename = getAttribute(i, "file");

                if (!CGE::hasContent(filename)) continue;

                cout << "found sheet " << filename << endl;

                for (xml_node<>* j = i->first_node(RegionNode); j;
                    j = j->next_sibling(RegionNode))
                {
                    const char* id = getAttribute(j, "id");
                    const char* x = getAttribute(j, "x");
                    const char* y = getAttribute(j, "y");
                    const char* w = getAttribute(j, "w");
                    const char* h = getAttribute(j, "h");

                    if (!CGE::hasContent(id)
                        || !CGE::hasContent(x)
                        || !CGE::hasContent(y)
                        || !CGE::hasContent(w)
                        || !CGE::hasContent(h))
                    {
                        continue;
                    }

                    cout << "    found region " << id << endl;

                    Region region;
                    CGE::tryParse(x, region.x);
                    CGE::tryParse(y, region.y);
                    CGE::tryParse(w, region.w);
                    CGE::tryParse(h, region.h);

                    mRegions[id] = region;

                    cout << "extracted region: " << region << endl;
                }
            }

            for (xml_node<>* i = root->first_node(AnimationNode); i;
                i = i->next_sibling(AnimationNode))
            {
                const char* id = getAttribute(i, "id");

                if (!CGE::hasContent(id)) continue;

                Animation animation;
                animation.firstFrame = NULL;

                Frame** currentFrame = &animation.firstFrame;

                for (xml_node<>* j = i->first_node(FrameNode); j;
                    j = j->next_sibling(FrameNode))
                {
                    const char* regionName = getAttribute(j, "region");

                    if (!CGE::hasContent(regionName)) continue;

                    const char* duration = getAttribute(j, "duration");

                    if (!CGE::hasContent(duration)) continue;

                    const Region* region
                        = CGE::tryGet(mRegions, string(regionName));

                    if (region)
                    {
                        Frame* frame = (Frame*)
                            CGE::allocate(sizeof(Frame), SpriteHeap);
                        frame->region = region;
                        frame->nextFrame = NULL;
                        CGE::tryParse(duration, frame->duration);

                        cout << "region " << *region << " added to animation "
                            << id << " with duration of " << frame->duration
                            << endl;

                        *currentFrame = frame;
                        currentFrame = &frame->nextFrame;
                    }
                    else
                    {
                        cout << "invalid region name: " << regionName << endl;
                    }
                }

                if (animation.firstFrame)
                    mAnimations[id] = animation;
            }
        }
    }

    CGE::release(content);
}

Sprite::~Sprite()
{
    for (map<string, Animation>::const_iterator i = mAnimations.begin();
        i != mAnimations.end(); ++i)
    {
        Frame* frame = i->second.firstFrame;

        while (frame)
        {
            Frame* deadFrame = frame;
            frame = frame->nextFrame;
            CGE::release(deadFrame);
        }
    }
}

ostream& operator<<(ostream& inStream, const Sprite::Region& inRegion)
{
    inStream << inRegion.x << ' ' << inRegion.y << ' ' << inRegion.w << ' '
        << inRegion.h;
    return inStream;
}
