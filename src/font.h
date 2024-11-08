/* hacktv - Analogue video transmitter for the HackRF                    */
/*=======================================================================*/
/* Copyright 2020 Philip Heron <phil@sanslogic.co.uk>                    */
/*                                                                       */
/* This program is free software: you can redistribute it and/or modify  */
/* it under the terms of the GNU General Public License as published by  */
/* the Free Software Foundation, either version 3 of the License, or     */
/* (at your option) any later version.                                   */
/*                                                                       */
/* This program is distributed in the hope that it will be useful,       */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of        */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         */
/* GNU General Public License for more details.                          */
/*                                                                       */
/* You should have received a copy of the GNU General Public License     */
/* along with this program.  If not, see <http://www.gnu.org/licenses/>. */


#ifndef FONT_H_
#define FONT_H_

#include <ft2build.h>
#include FT_FREETYPE_H
#include "video.h"

#define TEXT_POS_CENTRE 0
#define TEXT_POS_LEFT 1
#define TEXT_POS_RIGHT 2
#define NO_TEXT_SHADOW 0
#define TEXT_SHADOW 1
#define NO_TEXT_BOX 0
#define TEXT_BOX 1
#define TEXT_TIMESTAMP 0
#define TEXT_SUBTITLE 1
#define TEXT_GENERIC 1

typedef struct {
	uint32_t *video;
	int video_width;
	int video_height;
	float video_ratio;
	FT_Face fontface;
	int font_size;
	char *font_name;
	float x_loc;
	float y_loc;
	char *text;
} av_font_t;


extern int font_init(av_t *av, int size, float ratio, void *conf);
extern void print_subtitle(av_font_t *av, uint32_t *vid, int linesize, char *fmt);
extern void print_generic_text(av_font_t *font, uint32_t *vid, int linesize, char *fmt, float pos_x, float pos_y, int shadow, int box, int colour, float transparency);
extern int display_bitmap_subtitle(av_font_t *av, uint32_t *vid, int linesize, int w, int h, uint32_t *bitmap_data);
#endif
