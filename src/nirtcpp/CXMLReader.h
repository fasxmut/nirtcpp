// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_C_XML_READER_H_INCLUDED
#define NIRT_C_XML_READER_H_INCLUDED

#include "IXMLReader.h"

namespace nirt
{
#ifdef _NIRT_COMPILE_WITH_XML_
namespace io
{
	class IReadFile;

	//! creates an IXMLReader
	IXMLReader* createIXMLReader(IReadFile* file);

	//! creates an IXMLReader
	IXMLReaderUTF8* createIXMLReaderUTF8(IReadFile* file);
} // end namespace nirt
#else // _NIRT_COMPILE_WITH_XML_
	//! print a message that Nirtcpp is compiled without _NIRT_COMPILE_WITH_XML_
	void noXML();
#endif // _NIRT_COMPILE_WITH_XML_
} // end namespace io

#endif
