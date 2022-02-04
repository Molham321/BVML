#include "imageTools.h"

CImage ImageTools::getLinearHistrogramImageInRGB(CImage& image)
{
	CImage clone = image;

	int redHistogram[256] = { 0 };
	int greenHistogram[256] = { 0 };
	int blueHistogram[256] = { 0 };
	int redOutputHistogram[256] = { 0 };
	int greenOutputHistogram[256] = { 0 };
	int blueOutputHistogram[256] = { 0 };

	for (int x = 0; x < image.getHeight(); x++)
	{
		for (int y = 0; y < image.getWidth(); y++)
		{
			CColor color = image.getPointValue(x, y);

			// Histogramm in einem 256 Array realisieren
			redHistogram[color.getRed()] += 1;
			greenHistogram[color.getGreen()] += 1;
			blueHistogram[color.getBlue()] += 1;
		}
	}

	for (int k = 0; k < 256; k++)
	{
		for (int i = 0; i < k; i++)
		{
			// Berechne kumulierte Histogramm
			redOutputHistogram[k] += redHistogram[i];
			greenOutputHistogram[k] += greenHistogram[i];
			blueOutputHistogram[k] += blueHistogram[i];
		}
	}

	double widthHeight = (double)image.getWidth() * (double)image.getHeight();

	for (int x = 0; x < image.getHeight(); x++)
	{
		for (int y = 0; y < image.getWidth(); y++)
		{
			CColor color = clone.getPointValue(x, y);

			//Weisen Sie nun jedem Pixel mit RGB ri den neuen RGB hc(ri) zu.
			int redValue = 255 * ((double)redOutputHistogram[color.getRed()] / widthHeight);
			int greenValue = 255 * ((double)greenOutputHistogram[color.getGreen()] / widthHeight);
			int blueValue = 255 * ((double)blueOutputHistogram[color.getBlue()] / widthHeight);

			color.setRed(redValue);
			color.setGreen(greenValue);
			color.setBlue(blueValue);

			clone.setPointValue(x, y, color);
		}
	}
	return clone;
}
