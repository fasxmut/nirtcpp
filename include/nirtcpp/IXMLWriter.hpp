// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_I_XML_WRITER_H_INCLUDED
#define NIRT_I_XML_WRITER_H_INCLUDED

#include <nirtcpp/IReferenceCounted.hpp>
#include <nirtcpp/irrXML.hpp>

namespace nirt
{
namespace io
{
	//! An xml writer for wide characters, derived from IReferenceCounted.
	/** Call IFileSystem::createXMLReader(). to create an IXMLWriter */
	using IXMLWriter = IIrrXMLWriter<wchar_t, IReferenceCounted>;

	//! An xml writer for ASCII or UTF-8 characters, derived from IReferenceCounted.
	/** Call IFileSystem::createXMLReaderUtf8(). to create an IXMLWriter */
	using IXMLWriterUTF8 = IIrrXMLWriter<c8, IReferenceCounted>;

} // end namespace io
} // end namespace nirt

#endif
