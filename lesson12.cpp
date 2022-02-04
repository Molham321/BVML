
#include "imageTools.h"

// Gegeben sei ein Binärbild der Größe m × n	(image)
CImage ImageTools::houghTransformation(CImage& image)
{
	int greyValue;
	int greyValueHough;

	double M_PI = 3.1415;

	CColor newPixel(0);

	// Gegeben sei ein Binärbild der Größe m × n	(image)
	CImage oldPic = image.getGreyscaleImage();

	int o = 180;
	double p = sqrt(pow(oldPic.getWidth(), 2) + pow(oldPic.getHeight(), 2));

	//Erstelle ein Akkumulatorbild der Größe o × p
	CImage newPic(o, p, true);

	for (int i = 0; i < image.getHeight(); i++)
	{
		for (int k = 0; k < image.getWidth(); k++)
		{

			greyValue = oldPic.getPointValue(i, k).getGrey();

			if (greyValue > 0)
			{
				int x = i - oldPic.getWidth() / 2;
				int y = k - oldPic.getHeight() / 2;

				for (int z = 0; z <= 180; z++)
				{
					double O = M_PI / o * z;
					double r = x * cos(O) + y * sin(O);
					int j = p / 2 + round(r);

					greyValueHough = newPic.getPointValue(z, j).getGrey();
					greyValueHough++;
					newPixel.setGrey(greyValueHough);
					newPic.setPointValue(z, j, newPixel);
				}
			}
		}
	}

	return newPic;
}