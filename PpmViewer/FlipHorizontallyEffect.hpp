#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"

// VECTOR SUBSCRIPT ERROR

class FlipHorizontallyEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		// int row_counter = doc.getHeight() - 1;
		vector<vector<Pixel>> temp = doc.getRgbData();

		for (int i = 0; i < temp.size(); i++)
		{
			int col_counter = doc.getWidth() - 1;

			for (int j = 0; j < temp[i].size(); j++)
			{
				Pixel& p = doc[i][col_counter];
				Pixel q = temp[i][j];

				p = q;

				col_counter -= 1;

			}
		}
	}
};