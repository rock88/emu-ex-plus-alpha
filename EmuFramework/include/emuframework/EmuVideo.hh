#pragma once

/*  This file is part of EmuFramework.

	Imagine is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Imagine is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with EmuFramework.  If not, see <http://www.gnu.org/licenses/> */

#include <imagine/gfx/Texture.hh>

class EmuVideo
{
public:
	Gfx::PixmapTexture vidImg;
	IG::Pixmap vidPix {PixelFormatRGB565};
	char *pixBuff{};
	uint vidPixAlign = Gfx::Texture::MAX_ASSUME_ALIGN;

public:
	constexpr EmuVideo() {}
	void initPixmap(char *pixBuff, const PixelFormatDesc *format, uint x, uint y, uint pitch = 0);
	void reinitImage();
	void clearImage();
	void resizeImage(uint x, uint y, uint pitch = 0);
	void resizeImage(uint xO, uint yO, uint x, uint y, uint totalX, uint totalY, uint pitch = 0);
	void initImage(bool force, uint x, uint y, uint pitch = 0);
	void initImage(bool force, uint xO, uint yO, uint x, uint y, uint totalX, uint totalY, uint pitch = 0);
	void takeGameScreenshot();
	bool isExternalTexture();
};