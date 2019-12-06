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

		int current_height = doc.getHeight();
		int current_width = doc.getWidth();

		int temp_width = doc.getWidth();
		doc.setWidth(doc.getHeight());
		doc.setHeight(temp_width);

		current_height = doc.getHeight();
		current_width = doc.getWidth();
		
		// ISSUES BEGIN BELOW

		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc[i][j];
				p = temp[i][j];
			}
		}
	}
};