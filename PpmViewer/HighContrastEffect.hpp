#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"

int extreme_value(int value)
{
	if (value > (255 / 2))
	{
		value = 255;
	}
	else
	{
		value = 0;
	}
	return value;
}

class HighContrastEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc[i][j];
				p.red = extreme_value(p.red);
				p.green = extreme_value(p.green);
				p.blue = extreme_value(p.blue);

				//not necessary as we're using references but it makes our intent more clear
				doc[i][j] = p;
			}
		}
	}
};