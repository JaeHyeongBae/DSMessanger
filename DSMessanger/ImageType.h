#pragma once
#include <string>
class ImageType
{
public:
	ImageType();
	ImageType(std::string src)
	{
		this->src = src;
	}
	~ImageType();

	std::string src;
};

