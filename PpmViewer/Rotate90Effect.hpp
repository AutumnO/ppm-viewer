#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class Rotate90Effect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		int counter = 0;
		vector<vector<Pixel>> temp;

		temp.resize(doc.getWidth());
		for (int c = 0; c < doc.getWidth(); c++)
		{
			temp[c].resize(doc.getHeight());
		}

		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel p = doc[i][j];
				temp[counter][doc.getHeight() - (i + 1)] = p;
				counter++;
			}
			counter = 0;
		}

		doc.switchDimensions();

		doc.setRgbDataTo(temp);

	}
};