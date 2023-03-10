#include <stdio.h>

int strcmp(char *a, char *b)
{
	if (a[0] != '\0' || b[0] != '\0')
	{
		if (a[0] != b[0])
			return 0;
	}
	return 1;
}

int main()
{
	char c[8][4] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	int len[8] = { 2, 2, 3, 2, 2, 2, 2, 2 };
	char in[101] = { 0, };
	int cnt = 0;
	int idx = 0, find = 0;
	scanf("%s", in);
	
	while (in[idx] != '\0')
	{
		for (int i = 0; i < 8; i++)
		{
			find = 1;
			for (int j = 0; j < len[i]; j++)
			{
				if (c[i][j] != in[idx + j])
					find = 0;
			}

			if (find)
			{
				idx += len[i] - 1;
				break;
			}
		}
		cnt++;
		idx++;
	}
	
	printf("%d\n", cnt);

	return 0;
}