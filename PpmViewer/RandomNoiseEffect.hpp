#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"

int range_check(int value)
{
	if (value < 0)
	{
		value = 0;
	}
	else if (value > 255)
	{
		value = 255;
	}
	return value;
}

class RandomNoiseEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc[i][j];
				int noise_change = (rand() % 20 - 10);

				p.red = range_check(p.red += noise_change);
				p.green = range_check(p.green += noise_change);
				p.blue = range_check(p.blue += noise_change);

				//not necessary as we're using references but it makes our intent more clear
				doc[i][j] = p;
			}
		}
	}
};