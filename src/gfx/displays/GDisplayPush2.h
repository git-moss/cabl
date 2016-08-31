/*
        ##########    Copyright (C) 2015 Vincenzo Pacella
        ##      ##    Distributed under MIT license, see file LICENSE
        ##      ##    or <http://opensource.org/licenses/MIT>
        ##      ##
##########      ############################################################# shaduzlabs.com #####*/

#pragma once

#include "gfx/GDisplay.h"

#include <map>

namespace sl
{
namespace cabl
{

//--------------------------------------------------------------------------------------------------

class GDisplayPush2 : public GDisplay
{
public:
  //! Constructor
  /*!
     \param width_  Display width in pixels
     \param height_ Display height in pixels
     \param height_ Number of data chunks (Default value is 8)
     */
  GDisplayPush2();

  void white() override;

  void black() override;

protected:
  //! Initialize the display
  void initializeImpl() override;

  //! \return The width of the display in bytes
  uint16_t canvasWidthInBytesImpl() const override;

  //! Set a pixel
  /*!
     \param x_               The X coordinate of the pixel
     \param y_               The Y coordinate of the pixel
     \param color_           The pixel color (RGB + monochrome)
     \param bSetDirtyChunk_  If TRUE, the dirty flag for the pertaining chunk is set
     */
  void setPixelImpl(uint16_t x_, uint16_t y_, const util::ColorRGB& color_, bool bSetDirtyChunk_ = true) override;

  //! Get the pixel value as an RGB color
  /*!
     \param x_               The X coordinate of the pixel
     \param y_               The Y coordinate of the pixel
     \return                 The color of the selected pixel
     */
  util::ColorRGB pixelImpl(uint16_t x_, uint16_t y_) const override;
};

//--------------------------------------------------------------------------------------------------

} // namespace cabl
} // namespace sl
