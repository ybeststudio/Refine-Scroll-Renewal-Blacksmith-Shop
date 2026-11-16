// Ara:
	MEMO_SCROLL				= 5,	// 100%	Notiz des Schmieds, Notiz des Weisen [-[70027, 72306], [70028, 72307]-]	-> Nur +4 Items
	BDRAGON_SCROLL			= 6,	// 
};

// Altina ekle:
#ifdef ENABLE_REFINE_SCROLL_RENEWAL
enum
{
	RITUAL_STONE			= 7,
	HONOR_SCROLL			= 11,
	DRAGON_SCROLL_RENEWAL	= 12,
	ASCENSION_SCROLL		= 13,
	ENIGMA_SCROLL			= 14,
};

static bool RefineScrollRenewal_CanUse(LPCHARACTER ch, LPITEM scroll, LPITEM item)
{
#ifdef ENABLE_ENERGY_CRYSTAL
	if (EnergyCrystal::IsCrystalScroll(scroll->GetVnum()))
		return true;	// energy crystal scrolls: own rules (energy_crystal.cpp)
#endif
	const int level = item->GetLevelLimit();
	bool ok = true;

	switch (scroll->GetValue(0))
	{
		case HONOR_SCROLL:			ok = level <= 42; break;
		case DRAGON_SCROLL_RENEWAL:	ok = level <= 105; break;
		case ASCENSION_SCROLL:		ok = level > 105 && item->GetRefineLevel() < 4; break;
		case ENIGMA_SCROLL:			ok = false; break;
		case RITUAL_STONE:			ok = level > 105; break;
		case MUSIN_SCROLL:			ok = level <= 105; break;
		case YAGONG_SCROLL:			ok = level <= 75; break;
		case HYUNIRON_CHN:			ok = level <= 105; break;
		default:					break;
	}

	if (!ok)
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You cannot upgrade items with this Scroll."));
	return ok;
}

static bool RefineScrollRenewal_Rule(LPITEM scroll, LPITEM item, int baseProb, BYTE& type, int& prob, bool& keep)
{
#ifdef ENABLE_ENERGY_CRYSTAL
	if (EnergyCrystal::IsCrystalScroll(scroll->GetVnum()))
		return false;
#endif
	static const int yagong_prob[9] = { 100, 100, 90, 80, 70, 60, 50, 30, 20 };

	switch (scroll->GetValue(0))
	{
		case MUSIN_SCROLL:
		case HONOR_SCROLL:
		case ASCENSION_SCROLL:
			type = REFINE_TYPE_MUSIN;
			prob = 100;
			keep = true;
			return true;

		case DRAGON_SCROLL_RENEWAL:
			type = REFINE_TYPE_SCROLL;
			prob = MIN(100, baseProb + 10);
			keep = false;
			return true;

		case YAGONG_SCROLL:
			type = REFINE_TYPE_HYUNIRON;
			prob = yagong_prob[MINMAX(0, item->GetRefineLevel(), 8)];
			keep = true;
			return true;

		case RITUAL_STONE:
			type = REFINE_TYPE_HYUNIRON;
			prob = baseProb;
			keep = true;
			return true;
	}
	return false;
}
#endif


// bool CHARACTER::DoRefineWithScroll(LPITEM item, ...) icinde:
// Ara:
			return false;
		}
	}

// Altina ekle:
#ifdef ENABLE_REFINE_SCROLL_RENEWAL
	if (!RefineScrollRenewal_CanUse(this, pkItemScroll, item))
		return false;
#endif


// bool CHARACTER::DoRefineWithScroll(LPITEM item, ...) icinde:
// Ara:
	// fix pergaminos
	if (pkItemScroll->GetVnum() == 39022 || pkItemScroll->GetVnum() == 71032 || pkItemScroll->GetVnum() == 76009)
		success_prob = prt->prob + 10;

// Altina ekle:
#ifdef ENABLE_REFINE_SCROLL_RENEWAL
	{
		BYTE bRuleType = 0;
		int iRuleProb = success_prob;
		bool bRuleKeep = false;
		if (RefineScrollRenewal_Rule(pkItemScroll, item, prt->prob, bRuleType, iRuleProb, bRuleKeep))
		{
			success_prob = iRuleProb;
			bDestroyWhenFail = bRuleKeep;
		}
	}
#endif


// bool CHARACTER::RefineInformation(BYTE bCell, BYTE bType, int iAdditionalCell) icinde:
// Ara:
		p.cost = ComputeRefineFee(prt->cost);
	//END_MAIN_QUEST_LV7
	p.prob = prt->prob;

// Altina ekle:
#ifdef ENABLE_REFINE_SCROLL_RENEWAL
	if (iAdditionalCell >= 0 && bType != REFINE_TYPE_NORMAL && bType != REFINE_TYPE_MONEY_ONLY)
	{
		LPITEM scroll = GetInventoryItem(iAdditionalCell);
		BYTE bRuleType = bType;
		int iRuleProb = p.prob;
		bool bRuleKeep = false;
		if (scroll && scroll->GetType() == ITEM_USE && scroll->GetSubType() == USE_TUNING && RefineScrollRenewal_Rule(scroll, item, prt->prob, bRuleType, iRuleProb, bRuleKeep))
			p.prob = iRuleProb;
	}
#endif


// bool CHARACTER::RefineItem(LPITEM pkItem, LPITEM pkTarget) icinde:
// Ara:
			ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You cannot upgrade this item."));
			return false;
		}

// Altina ekle:
#ifdef ENABLE_REFINE_SCROLL_RENEWAL
		if (!RefineScrollRenewal_CanUse(this, pkItem, pkTarget))
			return false;

		BYTE bRuleType = 0;
		int iRuleProb = 0;
		bool bRuleKeep = false;
		if (RefineScrollRenewal_Rule(pkItem, pkTarget, 0, bRuleType, iRuleProb, bRuleKeep))
		{
			if (pkTarget->GetRefineSet() == 501)
				return false;
			RefineInformation(pkTarget->GetCell(), bRuleType, pkItem->GetCell());
		}
		else
#endif

