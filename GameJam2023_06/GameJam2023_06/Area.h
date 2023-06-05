#pragma once
#pragma once

typedef struct Area
{
	float width;
	float height;

	Area operator +(Area area)
	{
		Area ret;
		ret.width = this->width + area.width;
		ret.height = this->height + area.height;

		return ret;
	}


	Area operator -(Area area)
	{
		Area ret;
		ret.width = this->width - area.width;
		ret.height = this->height - area.height;

		return ret;
	}


	Area operator *(Area area)
	{
		Area ret;
		ret.width = this->width * area.width;
		ret.height = this->height * area.height;

		return ret;
	}


	Area operator /(Area area)
	{
		Area ret;
		ret.width = this->width / area.width;
		ret.height = this->height / area.height;

		return ret;
	}

	Area operator /(float num)
	{
		Area ret;
		ret.width = this->width / num;
		ret.height = this->height / num;

		return ret;
	}

	Area operator =(Area area)
	{
		this->width = area.width;
		this->height = area.height;

		return *this;
	}


	bool operator==(Area area)
	{
		bool ret = (this->width == area.width && this->height == area.height);
		return ret;
	}

	bool operator!=(Area area)
	{
		bool ret = (this->width != area.width || this->height != area.height);
		return ret;
	}


}Area;
