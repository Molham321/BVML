#include "imageTools.h"

//Global definiert, damit in measure und serie5Aufg1 verfuegbar
int min;
int max;
int med;

int cmpfunc(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
void ImageTools::measure(int list[], int length)
{
	qsort(list, 49, sizeof(int), cmpfunc);
	min = list[0];
	max = list[length * length - 1];
	med = list[(length * length - 1) / 2];
}
void ImageTools::serie5Aufg1(CImage& image)
{
	int SMax = 7;
	int array[49];
	int windowSize = 3;
	int a1, a2, b1, b2;

	int m = image.getHeight();
	int n = image.getWidth();
	bool abort = true;
	int index = 0;

	CImage medianImage(m, n, true);	//leeres Grauwertbild anlegen

	CColor temPoint(0);
	for (int i = 0; i < 49; i++)
	{
		array[i] = 1000;
	}

	for (int x = SMax / 2; x < m - SMax / 2; x++)
	{
		for (int y = SMax / 2; y < n - SMax; y++)
		{
			windowSize = 3;
			while (abort)
			{
				index = 0;
				//Medianarray fuellen 
				for (int i = -windowSize / 2; i <= windowSize / 2; i++)
				{
					for (int j = -windowSize / 2; j <= windowSize / 2; j++)
					{
						array[index] = image.getPointValue(x + i, y + j).getGrey();
						index++;
					}
				}
				for (int k = index; k < 49; k++) //Auffuellen des restlichen Arrays mit zu gro�en Werten 
				{
					array[k] = 1000;
				}

				measure(array, windowSize); // min, med, max berechnen

				a1 = med - min;
				a2 = med - max;

				if (a1 > 0 && a2 < 0)	//go to Level B, falls wirklich min < med < max
				{
					b1 = image.getPointValue(x, y).getGrey() - min;
					b2 = image.getPointValue(x, y).getGrey() - max;
					if (b1 > 0 && b2 < 0) //Grauwert setzen
					{
						temPoint.setGrey(image.getPointValue(x, y).getGrey());
						medianImage.setPointValue(x, y, temPoint);
						abort = false;
						break;
					}
					else // Median setzen
					{
						temPoint.setGrey(med);
						medianImage.setPointValue(x, y, temPoint);
						abort = false;
						break;
					}
				}
				else if (windowSize < SMax) //Fenstergroesse erhoehen und in Level A bleiben, falls entweder min = med oder med = max, weil dann das Fenster nicht gross genug war
				{
					windowSize += 2;
				}
				else //Falls maximale Fenstergroesse erreicht wurde, dann handelt es sich vermutlich um eine homogene Flaeche und wir gehen einfach zum naechsten Pixel ueber
				{
					temPoint.setGrey(image.getPointValue(x, y).getGrey());
					medianImage.setPointValue(x, y, temPoint);
					abort = false;
					break;
				}
			}
			abort = true;
		}
	}
	medianImage.showImage("adaptives Medianfilter");
}