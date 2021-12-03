#include "imageTools.h"

void ImageTools::hairWavelets()
{
	CImage Calvin("Images/calvin.bmp");
	Calvin.showImage();

	Calvin = Calvin.getGreyscaleImage();

	int height = Calvin.getHeight();
	int width = Calvin.getWidth();

	double* vektorV = 0;

	for (int i = 0; i < 2; i++)
	{
		vektorV = new double[width];

		for (int x = 0; x < height; x++)
		{
			for (int y = 0; y < width; y++)
			{
				vektorV[y] = Calvin.getPointValue(x, y).getGrey();
			}

			for (int y = 0; y < width / 2; y++)
			{
				CColor grey = Calvin.getPointValue(x, y).getGrey();
			
				double newPixel = (vektorV[(2 * y) + 1] + vektorV[2 * y]) / 2;
				grey.setGrey(newPixel);
				Calvin.setPointValue(x, y, grey);

				double errorPixel = (vektorV[(2 * y) + 1] - vektorV[2 * y]) / 2;
				grey.setGrey(errorPixel);
				Calvin.setPointValue(x, y + width / 2, grey);
			}
		}

		delete[] vektorV;

		vektorV = new double[height];

		for (int y = 0; y < width; y++)
		{
			for (int x = 0; x < height / 2; x++)
			{
				vektorV[x] = Calvin.getPointValue(x, y).getGrey();
			}

			for (int x = 0; x < height / 2; x++)
			{
				CColor grey = Calvin.getPointValue(x, y).getGrey();

				double newPixel = (vektorV[(2 * x) + 1] + vektorV[2 * x]) / 2;
				grey.setGrey(newPixel);
				Calvin.setPointValue(x, y, grey);

				double errorPixel = (vektorV[(2 * x) + 1] - vektorV[2 * x]) / 2;
				grey.setGrey(errorPixel + 128);
				Calvin.setPointValue(x + height / 2, y, grey);
			}
		}

		delete[] vektorV;

		height /= 2;
		width /= 2;
	}

	Calvin.showImage("vertical");

}
