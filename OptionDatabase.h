#ifndef QCDBEDIT_OPTIONDATABASE_H
#define QCDBEDIT_OPTIONDATABASE_H
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

class QString;
class QStringList;


namespace QCDBEdit {

   class Option;

   /// Essentially a wrapper class around an sqlite database holding
   /// information on program options.  The OptionDatabase is implemented 
   /// as a singleton to prevent multiple instances, references to which 
   /// can be obtained via the following construct:
   ///  
   /// \code
   ///   OptionDatabase &myOptionDatabase = OptionDatabase::instance();
   /// \endcode
   ///  
   /// \b Note: 
   ///  - Valid option values are stored in the database as a single string with
   ///    options separated by ':'.  This means a colon cannot be used in the
   ///    value string.
   ///  - Replacements can be entered into the database using '//'. So if the
   ///    option is entered as 'a//b' it will appear in the interface as a, and be
   ///    replaced with b in the input file.  This means the forward slash should
   ///    not be used in the value string either.
   ///  - The above has been extended to allow a//b1|b2|... so that several qchem
   ///    values can be read from file.
   class OptionDatabase {

      public:
         OptionDatabase(QString const& fileName);
         ~OptionDatabase() { }

         bool loaded() const { return m_okay;}
         bool insert(Option const& opt, bool const promptOnOverwrite = true);
         bool remove(QString const& name, bool const prompt = true);
         bool get(QString const& name, Option& opt);
         QStringList all();

      private:
         static QStringList s_dbFields;
         void init();
         bool execute(QString const&);
         bool m_okay;
   };

} // end namespace QCDBEdit

#endif
