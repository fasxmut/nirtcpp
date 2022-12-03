// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_I_XML_READER_H_INCLUDED
#define NIRT_I_XML_READER_H_INCLUDED

#include "IReferenceCounted.h"
#include "irrXML.h"

namespace nirt
{
namespace io
{
	//! An xml reader for wide characters, derived from IReferenceCounted.
	/** This XML Parser can read any type of text files from any source
	Nirtcpp can read. Just call IFileSystem::createXMLReader(). For more
	information on how to use the parser, see IIrrXMLReader */
	typedef IIrrXMLReader<wchar_t, IReferenceCounted> IXMLReader;

	//! An xml reader for ASCII or UTF-8 characters, derived from IReferenceCounted.
	/** This XML Parser can read any type of text files from any source
	Nirtcpp can read. Just call IFileSystem::createXMLReaderUTF8(). For
	more information on how to use the parser, see IIrrXMLReader */
	typedef IIrrXMLReader<c8, IReferenceCounted> IXMLReaderUTF8;

} // end namespace io
} // end namespace nirt

#endif
