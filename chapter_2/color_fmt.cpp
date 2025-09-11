#include <iostream>

void rgb_2_ycbcr(const int r, const int g, const int b, float& y, float& u, float& v);

void ycbcr_2_rgb(const float y, const float u, const float v, int& r, int& g, int& b);

int judge_range(const float x);

int main() 
{
	int r, g, b;
	float y, u, v;
	std::cin >> r >> g >> b;
	
	rgb_2_ycbcr(r, g, b, y, u, v);
	std::cout << "y=" << y << ", u=" << u << ", v="<< v << std::endl;

	ycbcr_2_rgb(y, u, v, r, g, b);
	std::cout << "r=" << r << ", g=" << g << ", b="<< b << std::endl;
	
	return 0;
}

void rgb_2_ycbcr(const int r, const int g, const int b, float& y, float& u, float& v) 
{
	y = 0.299 * r + 0.587 * g + 0.114 * b;
	u = -0.14713 * r - 0.28886 * g + 0.436 * b + 128;
	v = 0.615 * r - 0.51498 * g - 0.10001 * b + 128;
}

void ycbcr_2_rgb(const float y, const float u, const float v, int& r, int& g, int& b) 
{
	auto r_tmp = y * 1.0 + 1.13983 * (v - 128);
	auto g_tmp = y * 1.0 - 0.39465 * (u - 128) - 0.58060 * (v - 128);
	auto b_tmp = y * 1.0 + 2.03211 * (u - 128);
	
	r = judge_range(r_tmp);
	g = judge_range(g_tmp);
	b = judge_range(b_tmp);
}

int judge_range(const float x)
{
	auto max_x = x > 255.0 ? 255.0 : x;
	auto min_x = max_x > 0 ? max_x : 0.0;
	return int(min_x);
}