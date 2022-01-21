#include "imageTools.h"

CImage ImageTools::moravec(CImage& image)
{
	CImage greyscalemImage = image.getGreyscaleImage();
	CImage clone = image.getGreyscaleImage();

	//CImage greyscalemImage = ImageTools::getBinaryImage(image, 120);


	for (int x = 1; x < image.getHeight() - 1; x++)
	{
		for (int y = 1; y < image.getWidth() - 1; y++)
		{
			int value = 0;

			for (int i = -1; i <= 1; i++)
			{
				for (int j = -1; j <= 1; j++)
				{
					int color = greyscalemImage.getPointValue(x + i, y + j).getGrey();
					int aktuellePixel = greyscalemImage.getPointValue(x, y).getGrey();

					value += (abs(aktuellePixel - color));
				}
			}

			CColor color = clone.getPointValue(x, y);

			color.setGrey(value / 8);

			clone.setPointValue(x, y, color);
		}
	}

	return clone;
}