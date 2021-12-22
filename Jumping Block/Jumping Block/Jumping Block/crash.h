#pragma once
bool RectOver(double rec1[4], double rec2[4]) {
	if ((rec1[0] >= rec2[0]) && (rec1[0] < rec2[2]))
	{
		if ((rec1[1] >= rec2[1]) && (rec1[1] < rec2[3]))
			return 1;

		if ((rec1[3] > rec2[1]) && (rec1[3] <= rec2[3]))
			return 1;

		if ((rec2[1] >= rec1[1]) && (rec2[1] < rec1[3]))
			return 1;

		if ((rec2[3] > rec1[1]) && (rec2[3] <= rec1[3]))
			return 1;
	}

	if ((rec1[2] > rec2[0]) && (rec1[2] <= rec2[2]))
	{
		if ((rec1[1] >= rec2[1]) && (rec1[1] < rec2[3]))
			return 1;

		if ((rec1[3] > rec2[1]) && (rec1[3] <= rec2[3]))
			return 1;

		if ((rec2[1] >= rec1[1]) && (rec2[1] < rec1[3]))
			return 1;

		if ((rec2[3] > rec1[1]) && (rec2[3] <= rec1[3]))
			return 1;
	}

	if ((rec2[0] >= rec1[0]) && (rec2[0] < rec1[2]))
	{
		if ((rec1[1] >= rec2[1]) && (rec1[1] < rec2[3]))
			return 1;

		if ((rec1[3] > rec2[1]) && (rec1[3] <= rec2[3]))
			return 1;

		if ((rec2[1] >= rec1[1]) && (rec2[1] < rec1[3]))
			return 1;

		if ((rec2[3] > rec1[1]) && (rec2[3] <= rec1[3]))
			return 1;
	}

	if ((rec2[2] > rec1[0]) && (rec2[2] <= rec1[2]))
	{
		if ((rec1[1] >= rec2[1]) && (rec1[1] < rec2[3]))
			return 1;

		if ((rec1[3] > rec2[1]) && (rec1[3] <= rec2[3]))
			return 1;

		if ((rec2[1] >= rec1[1]) && (rec2[1] < rec1[3]))
			return 1;

		if ((rec2[3] > rec1[1]) && (rec2[3] <= rec1[3]))
			return 1;
	}

	return 0;
}