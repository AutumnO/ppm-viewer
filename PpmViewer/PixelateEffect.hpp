#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"

// NEEDS FIX

class PixelateEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		int distance = 5;
		vector<vector<Pixel>> temp = doc.getRgbData();

		for (int i = 0; i < doc.getHeight(); i++)
		{
			if (distance > doc.getWidth())
			{
				for (int j = 0; j < doc.getWidth(); j++)
				{
					Pixel& p = doc[i][j];
					p = temp[i][0];
				}
			}
			else
			{
				for (int j = 0; (j + distance) <= doc.getWidth(); j += distance)
				{
					for (int d = 1; d < distance; d++)
					{
						Pixel& p = doc[i][j + d];
						p = temp[i][j];
					}
				}
			}
		}
		
		if (distance > doc.getHeight())
		{
			for (int j = 1; j < doc.getWidth(); j++)
			{
				for (int i = 1; i < doc.getHeight(); i++)
				{
					Pixel& p = doc[i][j];
					p = doc[0][j];
				}
			}
		}
		else
		{
			for (int i = 0; (i + distance) <= temp.size(); i += distance)
			{
				for (int j = 0; j < temp[i].size(); j++) 
				{
					for (int d = 0; d < distance; d++)
					{
						Pixel& p = doc[i + d][j];
						p = doc[i][j];
					}
				}
			}
		}
	}
};