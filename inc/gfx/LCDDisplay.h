/*
        ##########    Copyright (C) 2015 Vincenzo Pacella
        ##      ##    Distributed under MIT license, see file LICENSE
        ##      ##    or <http://opensource.org/licenses/MIT>
        ##      ##
##########      ############################################################# shaduzlabs.com #####*/

#pragma once

#include <stdint.h>

#include "util/Types.h"

namespace sl
{
namespace kio
{
class LCDDisplay
{
  
public:
  
  /**
   * @defgroup LCDDisplay LCD display
   * @{
   */
  
//--------------------------------------------------------------------------------------------------
  
  /**
   * @defgroup Lifetime Constructor and destructor
   * @ingroup LCDDisplay
   * @{
   */
  
  //! Constructor
  /*!
   \param charsPerRow_     Number of chars per row
   \param nRows_           Number of rows
  */
  LCDDisplay(uint8_t numCharsPerRow_, uint8_t numRows_)
  : m_isDirty(false)
  , m_numCharsPerRow(numCharsPerRow_)
  , m_numRows(numRows_)
  {}
  
  //! Destructor
  virtual ~LCDDisplay(){}
  
  virtual void clear() {}
  
  virtual const tRawData& getData() const { return m_data; }
  
  /** @} */ // End of group Lifetime
 
//--------------------------------------------------------------------------------------------------
  
  /**
   * @defgroup Text Text
   * @ingroup LCDDisplay
   * @{
   */
  
  //! Print a single char
  /*!
   \param col_             The column at which the char must be printed
   \param row_             The row at which the char must be printed
   \param c_               The char to be printed
  */
  virtual void printChar(uint8_t col_, uint8_t row_, char c_){}
   
  //! Print a string
  /*!
   \param string_          The string to be printed
   \param row_             The row at which the string must be printed
   */
  virtual void setText(const std::string& string_, uint8_t row_){}  
  
  //! Print a number
  /*!
   \param value_           The number to be printed
   \param row_             The row at which the number must be printed
   */
  virtual void setText(unsigned value_, uint8_t row_){}  
  
  //! Fill characters in a row according to the value
  /*!
   \param value_           The value to be shown (0...1) by filling the available chars in a row
   \param row_             The row at which the value must be shown
   */
  virtual void setValue(float value_, uint8_t row_){}
  
  /**@}*/ // End of Text group
  
//--------------------------------------------------------------------------------------------------
  
  /**
   * @defgroup Access Access and state queries functions
   * @ingroup LCDDisplay
   * @{
   */

  
  //! Is any of the display rows dirty?
  /*!
   \return        true if the display must be redrawn, false otherwise
   */
  virtual bool isDirty() const { return m_isDirty; }

  //! Is the specified row dirty?
  /*!
   \param row_    The display row to check
   \return true if the display row must be redrawn, false otherwise
   */
  virtual bool isDirtyRow(uint8_t row_) const { return m_isDirty; }
  
  //! Reset the global dirty flag
  virtual void resetDirtyFlags(){ m_isDirty = false; }
  
  /** @} */ // End of group Access
  
//--------------------------------------------------------------------------------------------------
  
  /**
   * @defgroup Utility Utility/debug functions
   * @ingroup LCDDisplay
   * @{
   */
  
  virtual uint8_t getNumberOfCharsPerRow() const noexcept { return m_numCharsPerRow; }
  virtual uint8_t getNumberOfRows() const noexcept { return m_numRows; }
  
  /** @} */ // End of group Utility
  
  /** @} */ // End of group LCDDisplay
  
//--------------------------------------------------------------------------------------------------
protected:

  void setDirty(bool isDirty_){ m_isDirty = isDirty_; }
  tRawData& data(){ return m_data; }
  
private:

  bool                    m_isDirty;
  uint8_t                 m_numCharsPerRow;
  uint8_t                 m_numRows;

  tRawData                m_data;
  
};
  
//--------------------------------------------------------------------------------------------------
  
} // kio
} // sl