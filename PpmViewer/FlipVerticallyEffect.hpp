#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"

class FlipVerticallyEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		int row_counter = doc.getHeight() - 1;
		vector<vector<Pixel>> temp = doc.getRgbData();

		for (int i = 0; i < doc.getHeight(); i++)
		{
			doc[row_counter] = temp[i];
			
			row_counter -= 1;
		}
	}
};