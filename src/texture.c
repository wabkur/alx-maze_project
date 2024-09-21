#include "../headers/header.h"

static const char *textureFileNames[NUM_TEXTURES] = {
	"./images/redbrick.png",
	"./images/purplestone.png",
	"./images/mossystone.png",
	"./images/graystone.png",
	"./images/colorstone.png",
	"./images/bluestone.png",
	"./images/wood.png",
	"./images/eagle.png",
};

/**
 * WallTexturesready - load textures in the respective position
 *
*/
void WallTexturesready(void)
{
	int w;

	for (w = 0; w < NUM_TEXTURES; w++)
	{
		upng_t *upng;

		upng = upng_new_from_file(textureFileNames[w]);

		if (upng != NULL)
		{
			upng_decode(upng);
			if (upng_get_error(upng) == UPNG_EOK)
			{
				wallTextures[w].upngTexture = upng;
				wallTextures[w].width = upng_get_width(upng);
				wallTextures[w].height = upng_get_height(upng);
				wallTextures[w].texture_buffer = (color_t *)upng_get_buffer(upng);
			}
		}
	}

}

/**
 * freeWallTextures - free wall textures
 *
*/

void freeWallTextures(void)
{
	int w;

	for (w = 0; w < NUM_TEXTURES; w++)
		upng_free(wallTextures[w].upngTexture);
}