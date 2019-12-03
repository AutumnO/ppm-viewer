#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"

// VECTOR SUBSCRIPT ERROR

class FlipHorizontallyEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		int row_counter = doc.getHeight() - 1;
		int col_counter = doc.getWidth() -1;
		vector<vector<Pixel>> temp = doc.getRgbData();

		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc[i][col_counter];
				Pixel q = temp[i][j];

				p.red = q.red;
				p.green = q.green;
				p.blue = q.blue;

				col_counter -= 1;
				//not necessary as we're using references but it makes our intent more clear
				doc[i][j] = p;
			}
		}
	}
};