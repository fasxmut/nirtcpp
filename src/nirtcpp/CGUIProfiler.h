// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h
// Written by Michael Zeilfelder

#ifndef NIRT_C_GUI_PROFILER_H_INCLUDED
#define NIRT_C_GUI_PROFILER_H_INCLUDED

#include "IrrCompileConfig.h"
#ifdef _NIRT_COMPILE_WITH_GUI_

#include "IGUIProfiler.h"

namespace nirt
{

class IProfiler;
struct SProfileData;

namespace gui
{
	class IGUITable;

	//! Element to display profiler information
	class CGUIProfiler : public IGUIProfiler
	{
	public:
		//! constructor
		CGUIProfiler(IGUIEnvironment* environment, IGUIElement* parent, s32 id, core::rect<s32> rectangle, IProfiler* profiler);

		//! Show first page of profile data
		virtual void firstPage(bool includeOverview) override;

		//! Show next page of profile data
		virtual void nextPage(bool includeOverview) override;

		//! Show previous page of profile data
		virtual void previousPage(bool includeOverview) override;

		//! Try to show as many group-pages together as possible instead of showing at most one group per page.
		/** \param groupsTogether When true show several groups on one page, when false show max. one group per page. Default is false. */
		virtual void setShowGroupsTogether(bool groupsTogether) override;

		//! Can several groups be displayed per page?
		virtual bool getShowGroupsTogether() const override;

		//! Sets another skin independent font.
		virtual void setOverrideFont(IGUIFont* font) override;

		//! Gets the override font (if any)
		virtual IGUIFont* getOverrideFont() const override;

		//! Get the font which is used right now for drawing
		virtual IGUIFont* getActiveFont() const override;

		//! Sets whether to draw the background. By default disabled,
		virtual void setDrawBackground(bool draw) override;

		//! Checks if background drawing is enabled
		/** \return true if background drawing is enabled, false otherwise */
		virtual bool isDrawBackgroundEnabled() const override;

		//! Allows to freeze updates which makes it easier to read the numbers
		virtual void setFrozen(bool freeze) override;

		//! Are updates currently frozen
		virtual bool getFrozen() const override;

		//! Filters prevents data that doesn't achieve the conditions from being displayed
		virtual void setFilters(nirt::u32 minCalls, nirt::u32 minTimeSum, nirt::f32 minTimeAverage, nirt::u32 minTimeMax) override;

		virtual IGUIElement* getElementFromPoint(const core::position2d<s32>& point) override
		{
			// This element should never get focus from mouse-clicks
			return 0;
		}

		virtual void draw() override;

	protected:

		void updateDisplay();
		void fillRow(u32 rowIndex, const SProfileData& data, bool overviewTitle, bool groupTitle);
		u32 addDataToTable(u32 rowIndex, u32 dataIndex, u32 groupIndex);
		void rebuildColumns();

		IProfiler * Profiler;
		nirt::gui::IGUITable* DisplayTable;
		nirt::u32 CurrentGroupIdx;
		nirt::s32 CurrentGroupPage;
		nirt::s32 NumGroupPages;
		bool DrawBackground;
		bool Frozen;
		bool UnfreezeOnce;
		bool ShowGroupsTogether;
		nirt::u32 MinCalls;
		nirt::u32 MinTimeSum;
		nirt::f32 MinTimeAverage;
		nirt::u32 MinTimeMax;
	};

} // end namespace gui
} // end namespace nirt

#endif // _NIRT_COMPILE_WITH_GUI_

#endif
