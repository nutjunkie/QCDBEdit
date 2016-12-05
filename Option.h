#ifndef QCDBEDIT_OPTION_H
#define QCDBEDIT_OPTION_H
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

#include <QString>
#include <QStringList>


namespace QCDBEdit {


   /// An Option object contains all the information related to a single
   /// program option.  The idea is that Options are smart configuration options
   /// that know what type they are (integer, string, etc.) the default value,
   /// valid options and embedded documentation. 
   class Option {

      friend class OptionDatabase;
      friend class EditOptionDialog;

      public:
         enum Type { Type_Integer, Type_Logical, Type_String,  
                     Type_Real,    Type_Array };

         enum Impl { Impl_None, Impl_Combo, Impl_Check, 
                     Impl_Text, Impl_Spin,  Impl_DSpin, Impl_Radio };
                  
         enum Field { Field_Name,    Field_Type,        Field_Default,  
                      Field_Options, Field_Description, Field_Implementation };

         enum Limit { Limit_Min, Limit_Max, Limit_Default, Limit_Step };

	     Option(QString const& name = QString(), 
                Type const& type = Type_Integer,
		   	    int const& defaultIndex = 0, 
                QString const& options = QString(),
			    QString const& description = QString(), 
                Impl const& implementation = Impl_None) 
	      : m_name(name), m_type(type), m_defaultIndex(defaultIndex),  
		    m_description(description), m_implementation(implementation) {
            optionArray(options);
          }

      ~Option() { destroy(); }

      Option(Option const& that) { copy(that); }

      Option const& operator=(Option const& that);

      // Accessors 
      QString const&     getName()        const { return m_name; }
      QString const&     getDescription() const { return m_description; }
      QStringList const& getOptions()     const { return m_options; }
      Type getType()            const { return m_type; }
      QString getTypeAsString() const;
      QString getImplAsString() const;
      int  getDefaultIndex()    const { return m_defaultIndex; }
      Impl getImplementation()  const { return m_implementation; }
      QString getOptionString() const { return optionString(); }
      QString getDefaultValue() const;
         
      int intMin() const;
      int intMax() const;
      int intDefault() const;
      int intStep() const;

      double doubleMin() const;
      double doubleMax() const;
      double doubleDefault() const;
      double doubleStep() const;

   protected:
      // Mutators
      void setName(QString const& name) { m_name = name.toUpper(); }
      void setType(Type const& type) { m_type = type; }
      void setDefault(int const& defaultIndex) { m_defaultIndex = defaultIndex; }
      void setOptions(QStringList const& options) { m_options = options; }
      void setDescription(QString const& description) { m_description = description; }
      void setImplementation(Impl const& impl) { m_implementation = impl; }
      void setOptions(QString const& options) { optionArray(options); }
      void setType(int const& type);
      void setImplementation(int const& impl);

   private:
      // Data members
      QString m_name;
      Type m_type;
      int m_defaultIndex;          // this is the default index in the m_options array
      QString m_description;
      Impl m_implementation;
      QStringList m_options;

      // Private member functions
      void copy(Option const&);
      void destroy();

      void optionArray(QString const& options);
      QString optionString() const;
};

} // end namespace QCDBEdit
#endif
