#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class BlurEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		vector<vector<Pixel>> temp = doc.getRgbData();
		
		for (int c = 0; c < 1; c++)
		{
			for (int i = 0; i < doc.getHeight(); i++)
			{
				for (int j = 0; j < doc.getWidth(); j++)
				{
					if (j == 0)
					{
						Pixel& p = doc[i][j];
						Pixel q = temp[i][j];
						Pixel r = temp[i][j + 1];
						int average = (r.red + q.red) / 2;
						p.red = average;
						average = (r.green + q.green) / 2;
						p.green = average;
						average = (r.blue + q.blue) / 2;
						p.blue = average;
					}
					else if (j == (doc.getWidth() - 1))
					{
						Pixel& p = doc[i][j];
						Pixel q = temp[i][j];
						Pixel r = temp[i][j - 1];
						int average = (r.red + q.red) / 2;
						p.red = average;
						average = (r.green + q.green) / 2;
						p.green = average;
						average = (r.blue + q.blue) / 2;
						p.blue = average;
					}
					else
					{
						Pixel& p = doc[i][j];
						Pixel q = temp[i][j - 1];
						Pixel r = temp[i][j];
						Pixel s = temp[i][j + 1];
						int average = (q.red + r.red + s.red) / 3;
						p.red = average;
						average = (q.green + r.green + s.green) / 3;
						p.green = average;
						average = (q.blue + r.blue + s.blue) / 3;
						p.blue = average;
					}
				}
			}
			
			temp = doc.getRgbData();
			for (int j = 0; j < doc.getWidth(); j++)
			{
				for (int i = 0; i < doc.getHeight(); i++)
				{
					if (i == 0)
					{
						Pixel& p = doc[i][j];
						Pixel q = temp[i][j];
						Pixel r = temp[i + 1][j];
						int average = (q.red + r.red) / 2;
						p.red = average;
						average = (q.green + r.green) / 2;
						p.green = average;
						average = (q.blue + r.blue) / 2;
						p.blue = average;
					}
					else if (i == (doc.getHeight() - 1))
					{
						Pixel& p = doc[i][j];
						Pixel q = temp[i][j];
						Pixel r = temp[i - 1][j];
						int average = (q.red + r.red) / 2;
						p.red = average;
						average = (q.green + r.green) / 2;
						p.green = average;
						average = (q.blue + r.blue) / 2;
						p.blue = average;
					}
					else
					{
						Pixel& p = doc[i][j];
						Pixel q = temp[i - 1][j];
						Pixel r = temp[i][j];
						Pixel s = temp[i + 1][j];
						int average = (q.red + r.red + s.red) / 3;
						p.red = average;
						average = (q.green + r.green + s.green) / 3;
						p.green = average;
						average = (q.blue + r.blue + s.blue) / 3;
						p.blue = average;
					}
				}
			}
		}
	}
};