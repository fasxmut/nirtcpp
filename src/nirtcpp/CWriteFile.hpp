// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_C_WRITE_FILE_H_INCLUDED
#define NIRT_C_WRITE_FILE_H_INCLUDED

#include <stdio.h>
#include <nirtcpp/IWriteFile.hpp>
#include <nirtcpp/irrString.hpp>

namespace nirt
{

namespace io
{

	/*!
		Class for writing a real file to disk.
	*/
	class CWriteFile : public IWriteFile
	{
	public:

		CWriteFile(const io::path& fileName, bool append);

		virtual ~CWriteFile();

		//! Reads an amount of bytes from the file.
		virtual size_t write(const void* buffer, size_t sizeToWrite) override;

		//! Changes position in file, returns true if successful.
		virtual bool seek(long finalPos, bool relativeMovement = false) override;

		//! Returns the current position in the file.
		virtual long getPos() const override;

		//! Returns name of file.
		virtual const io::path& getFileName() const override;

		//! Flush the content of the buffer in the file
		virtual bool flush() override;

		//! returns if file is open
		bool isOpen() const;

		//! creator method
		static IWriteFile* createWriteFile(const io::path& fileName, bool append);

	private:

		//! opens the file
		void openFile(bool append);

		io::path Filename;
		FILE* File;
		long FileSize;
	};

} // end namespace io
} // end namespace nirt

#endif
