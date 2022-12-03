// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_C_MEMORY_READ_FILE_H_INCLUDED
#define NIRT_C_MEMORY_READ_FILE_H_INCLUDED

#include "IMemoryReadFile.h"
#include "IWriteFile.h"
#include "irrString.h"

namespace nirt
{

namespace io
{

	/*!
		Class for reading from memory.
	*/
	class CMemoryReadFile : public IMemoryReadFile
	{
	public:

		//! Constructor
		CMemoryReadFile(const void* memory, long len, const io::path& fileName, bool deleteMemoryWhenDropped);

		//! Destructor
		virtual ~CMemoryReadFile();

		//! returns how much was read
		virtual size_t read(void* buffer, size_t sizeToRead) override;

		//! changes position in file, returns true if successful
		virtual bool seek(long finalPos, bool relativeMovement = false) override;

		//! returns size of file
		virtual long getSize() const override;

		//! returns where in the file we are.
		virtual long getPos() const override;

		//! returns name of file
		virtual const io::path& getFileName() const override;

		//! Get the type of the class implementing this interface
		virtual EREAD_FILE_TYPE getType() const override
		{
			return ERFT_MEMORY_READ_FILE;
		}

		//! Get direct access to internal buffer
		virtual const void *getBuffer() const override
		{
			return Buffer;
		}

	private:

		const void *Buffer;
		long Len;
		long Pos;
		io::path Filename;
		bool deleteMemoryWhenDropped;
	};

	/*!
		Class for writing to memory.
	*/
	class CMemoryWriteFile : public IWriteFile
	{
	public:

		//! Constructor
		CMemoryWriteFile(void* memory, long len, const io::path& fileName, bool deleteMemoryWhenDropped);

		//! Destructor
		virtual ~CMemoryWriteFile();

		//! returns how much was written
		virtual size_t write(const void* buffer, size_t sizeToWrite) override;

		//! changes position in file, returns true if successful
		virtual bool seek(long finalPos, bool relativeMovement = false) override;

		//! returns where in the file we are.
		virtual long getPos() const override;

		//! returns name of file
		virtual const io::path& getFileName() const override;

		virtual bool flush() override;

	private:

		void *Buffer;
		long Len;
		long Pos;
		io::path Filename;
		bool deleteMemoryWhenDropped;
	};

} // end namespace io
} // end namespace nirt

#endif
