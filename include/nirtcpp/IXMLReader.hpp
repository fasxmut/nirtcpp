// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_I_XML_READER_H_INCLUDED
#define NIRT_I_XML_READER_H_INCLUDED

#include <nirtcpp/IReferenceCounted.hpp>
#include <nirtcpp/irrXML.hpp>

namespace nirt
{
namespace io
{
	//! An xml reader for wide characters, derived from IReferenceCounted.
	/** This XML Parser can read any type of text files from any source
	Nirtcpp can read. Just call IFileSystem::createXMLReader(). For more
	information on how to use the parser, see IIrrXMLReader */
	using IXMLReader = IIrrXMLReader<wchar_t, IReferenceCounted>;

	//! An xml reader for ASCII or UTF-8 characters, derived from IReferenceCounted.
	/** This XML Parser can read any type of text files from any source
	Nirtcpp can read. Just call IFileSystem::createXMLReaderUTF8(). For
	more information on how to use the parser, see IIrrXMLReader */
	using IXMLReaderUTF8 = IIrrXMLReader<c8, IReferenceCounted>;

} // end namespace io
} // end namespace nirt

#endif
