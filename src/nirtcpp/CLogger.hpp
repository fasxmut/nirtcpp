// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_C_LOGGER_H_INCLUDED
#define NIRT_C_LOGGER_H_INCLUDED

#include <nirtcpp/ILogger.hpp>
#include "os.hpp"
#include <nirtcpp/irrString.hpp>
#include <nirtcpp/IEventReceiver.hpp>

namespace nirt
{

//! Class for logging messages, warnings and errors to stdout
class CLogger : public ILogger
{
public:

	CLogger(IEventReceiver* r);

	//! Returns the current set log level.
	virtual ELOG_LEVEL getLogLevel() const override;

	//! Sets a new log level.	virtual void setLogLevel(ELOG_LEVEL ll) override;
	virtual void setLogLevel(ELOG_LEVEL ll) override;

	//! Prints out a text into the log
	virtual void log(const c8* text, ELOG_LEVEL ll=ELL_INFORMATION) override;

	//! Prints out a text into the log
	virtual void log(const wchar_t* text, ELOG_LEVEL ll=ELL_INFORMATION) override;

	//! Prints out a text into the log
	virtual void log(const c8* text, const c8* hint, ELOG_LEVEL ll=ELL_INFORMATION) override;

	//! Prints out a text into the log
	virtual void log(const c8* text, const wchar_t* hint, ELOG_LEVEL ll=ELL_INFORMATION) override;

	//! Prints out a text into the log
	virtual void log(const wchar_t* text, const wchar_t* hint, ELOG_LEVEL ll=ELL_INFORMATION) override;

	//! Sets a new event receiver
	void setReceiver(IEventReceiver* r);

private:

	ELOG_LEVEL LogLevel;
	IEventReceiver* Receiver;
};

} // end namespace

#endif
