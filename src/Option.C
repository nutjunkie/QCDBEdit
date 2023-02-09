/*******************************************************************************

  Copyright (C) 2011 Andrew Gilbert

  This file is part of IQmol, a free molecular visualization program. See
  <http://iqmol.org> for more details.

  IQmol is free software: you can redistribute it and/or modify it under the
  terms of the GNU General Public License as published by the Free Software
  Foundation, either version 3 of the License, or (at your option) any later
  version.

  IQmol is distributed in the hope that it will be useful, but WITHOUT ANY
  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
  FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
  details.

  You should have received a copy of the GNU General Public License along
  with IQmol.  If not, see <http://www.gnu.org/licenses/>.

********************************************************************************/

#include "Option.h"
#include <QtDebug>


namespace QCDBEdit {

Option const& Option::operator=(Option const& that) 
{
   if (this != &that) {
      destroy();
      copy(that);
   }
   return *this;
}


// Private member function
void Option::destroy() 
{
   m_options.clear();
}


void Option::copy(Option const& that) 
{
   m_name           = that.m_name;
   m_type           = that.m_type;
   m_defaultIndex   = that.m_defaultIndex;
   m_options        = that.m_options;
   m_description    = that.m_description;
   m_implementation = that.m_implementation;
}


void Option::optionArray(QString const& options) 
{
   m_options = options.split(":",QString::SkipEmptyParts);
}


QString Option::optionString() const 
{
   return m_options.join(":");
}


QString Option::getDefaultValue() const 
{
   QString dv;
   if (0 <= m_defaultIndex && m_defaultIndex < m_options.count()) {
      dv = m_options[m_defaultIndex];
      int i(dv.indexOf("//"));
      if (i > 0) dv.truncate(i);
   }else {
     dv = "NOT SET";
   }
   return dv;
}


QString Option::getTypeAsString() const
{
   QString type;
   switch (getType()) {
      case Type_Integer:  type = "Integer";  break;
      case Type_Logical:  type = "Logical";  break;
      case Type_String:   type = "String";   break;
      case Type_Real:     type = "Real";     break;
      case Type_Array:    type = "Array";    break;
   }
   return type;
}


QString Option::getImplAsString() const
{
   QString impl;
   switch (m_implementation) {
      case Impl_None:  impl = "None";             break;
      case Impl_Combo: impl = "Combo box";        break;
      case Impl_Check: impl = "Check box";        break;
      case Impl_Text:  impl = "Line edit";        break;
      case Impl_Spin:  impl = "Spin box";         break;
      case Impl_DSpin: impl = "Double spin box";  break;
      case Impl_Radio: impl = "Radio box";        break;
   }
   return impl;
}


void Option::setType(int const& type) 
{
   if (type == Type_Integer) {
      m_type = Type_Integer;
   }else if (type == Type_Logical) {
      m_type = Type_Logical;
   }else if (type == Type_String) {
      m_type = Type_String;
   }else if (type == Type_Real) {
      m_type = Type_Real;
   }else if (type == Type_Array) {
      m_type = Type_Array;
   }
}




void Option::setImplementation(int const& impl) 
{
   if (impl == Impl_None) {
      m_implementation = Impl_None;
   }else if (impl == Impl_Combo) {
      m_implementation = Impl_Combo;
   }else if (impl == Impl_Check) {
      m_implementation = Impl_Check;
   }else if (impl == Impl_Text) {
      m_implementation = Impl_Text;
   }else if (impl == Impl_Spin) {
      m_implementation = Impl_Spin;
   }else if (impl == Impl_DSpin) {
      m_implementation = Impl_DSpin;
   }else if (impl == Impl_Radio) {
      m_implementation = Impl_Radio;
   }else {
      qDebug() << "ERROR: Option::setImplementation()\n"
               << "       Unknown Implementation type" << impl 
               << "for option" << m_name;
   }
}



int Option::intMin() const 
{
   int min(0);
   if (m_type == Type_Integer && m_options.count() == 4) {
      min = m_options[Limit_Min].toInt(); 
   }
   return min;
}


int Option::intMax() const 
{
   int max(100);
   if (m_type == Type_Integer && m_options.count() == 4) {
      max = m_options[Limit_Max].toInt(); 
   }
   return max;
}


int Option::intDefault() const 
{
   int def(0);
   if (m_type == Type_Integer && m_options.count() == 4) {
      def = m_options[Limit_Default].toInt(); 
   }
   return def;
}


int Option::intStep() const 
{
   int step(1);
   if (m_type == Type_Integer && m_options.count() == 4) {
      step = m_options[Limit_Step].toInt(); 
   }
   return step;
}


double Option::doubleMin() const 
{
   double min(0.0);
   if (m_type == Type_Real&& m_options.count() == 4) {
      min = m_options[Limit_Min].toDouble(); 
   }
   return min;
}


double Option::doubleMax() const 
{
   double max(1.0);
   if (m_type == Type_Real && m_options.count() == 4) {
      max = m_options[Limit_Max].toDouble(); 
   }
   return max;
}


double Option::doubleDefault() const 
{
   double def(0.0);
   if (m_type == Type_Real && m_options.count() == 4) {
      def = m_options[Limit_Default].toDouble(); 
   }
   return def;
}


double Option::doubleStep() const 
{
   double step(0.01);
   if (m_type == Type_Real && m_options.count() == 4) {
      step = m_options[Limit_Step].toDouble(); 
   }
   return step;
}

} // end namespace QCDBEdit
