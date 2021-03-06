/*
 * Scripts for Ascent MMORPG Server
 * Copyright (C) 2005-2010 Ascent Team <http://www.ascentemulator.net/>
 *
 * This software is  under the terms of the EULA License
 * All title, including but not limited to copyrights, in and to the AscentNG Software
 * and any copies there of are owned by ZEDCLANS INC. or its suppliers. All title
 * and intellectual property rights in and to the content which may be accessed through
 * use of the AscentNG is the property of the respective content owner and may be protected
 * by applicable copyright or other intellectual property laws and treaties. This EULA grants
 * you no rights to use such content. All rights not expressly granted are reserved by ZEDCLANS INC.
 *
 */

#include "StdAfx.h"
#include "Setup.h"

// Curgle Cranklehop
#define GOSSIP_CURGLE_CRANKLEHOP_1    "Please tell me more about the hippogryphs."
#define GOSSIP_CURGLE_CRANKLEHOP_2    "Please tell me more about the Gordunni ogres."

class CurgleCranklehop_Gossip : public GossipScript
{
public:
    void GossipHello(Object* pObject, Player* plr, bool AutoSend)
    {
        GossipMenu *Menu;
        objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1519, plr);
        Menu->AddItem( 0, GOSSIP_CURGLE_CRANKLEHOP_1, 1);
		Menu->AddItem( 0, GOSSIP_CURGLE_CRANKLEHOP_2, 2);
        
        if(AutoSend)
            Menu->SendTo(plr);
    }

    void GossipSelectOption(Object* pObject, Player* plr, uint32 Id, uint32 IntId, const char * Code)
    {
		if(pObject->GetTypeId()!=TYPEID_UNIT)
			return;
		
		GossipMenu * Menu;
        switch(IntId)
        {
        case 1:
			{
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1521, plr);
				Menu->SendTo(plr);
            }break;
		case 2:
			{
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1646, plr);
				Menu->SendTo(plr);
            }break;
		}
    }

    void Destroy()
    {
        delete this;
    }
};

// Trenton Lighthammer
#define GOSSIP_TRENTON_LIGHTHAMMER    "Tell me more, Trenton."

class TrentonLighthammer_Gossip : public GossipScript
{
public:
    void GossipHello(Object* pObject, Player* plr, bool AutoSend)
    {
        GossipMenu *Menu;
        objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1758, plr);
        Menu->AddItem( 0, GOSSIP_TRENTON_LIGHTHAMMER, 1);
        
        if(AutoSend)
            Menu->SendTo(plr);
    }

    void GossipSelectOption(Object* pObject, Player* plr, uint32 Id, uint32 IntId, const char * Code)
    {
		if(pObject->GetTypeId()!=TYPEID_UNIT)
			return;
		
		GossipMenu * Menu;
        switch(IntId)
        {
        case 1:
			{
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1759, plr);
				Menu->SendTo(plr);
            }break;
		}
    }

    void Destroy()
    {
        delete this;
    }
};

void SetupTanarisGossip(ScriptMgr * mgr)
{
	GossipScript * CurgleCranklehopGossip = (GossipScript*) new CurgleCranklehop_Gossip;
	GossipScript * TrentonLighthammerGossip = (GossipScript*) new TrentonLighthammer_Gossip;

	mgr->register_gossip_script(7763, CurgleCranklehopGossip);		// Curgle Cranklehop
	mgr->register_gossip_script(7804, TrentonLighthammerGossip);	// Trenton Lighthammer
}
