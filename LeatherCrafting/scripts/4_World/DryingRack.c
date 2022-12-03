class CleanedPelt_Base extends ItemBase{}
class CleanedWildboarPelt extends CleanedPelt_Base
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionAttach);
	};
};
class CleanedRabbitPelt extends CleanedPelt_Base
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionAttach);
	};
};
class CleanedCowPelt extends CleanedPelt_Base
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionAttach);
	};
};
class CleanedPigPelt extends CleanedPelt_Base
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionAttach);
	};
};
class CleanedDeerPelt extends CleanedPelt_Base
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionAttach);
	};
};
class CleanedGoatPelt extends CleanedPelt_Base
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionAttach);
	};
};
class CleanedBearPelt extends CleanedPelt_Base
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionAttach);
	};
};
class CleanedWolfPelt extends CleanedPelt_Base
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionAttach);
	};
};
class CleanedSheepPelt extends CleanedPelt_Base
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionAttach);
	};
};
class CleanedMouflonPelt extends CleanedPelt_Base
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionAttach);
	};
};
class UnfinishedDryingFrame extends ItemBase
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionAttach);
	};
};
class DryingFrame extends ItemBase
{	

	static float TimeTo_TanPelt_PerLeather = GetTanningLeatherWorkingSettings().TimeToTanPeltPerLeather;
	static float GardenLime_Used_PerLeather = GetTanningLeatherWorkingSettings().GardenLimeUsedPerLeather;
	static float WildboarPelt_to_Leather = GetTanningLeatherWorkingSettings().WildboarPeltToLeather;
	static float Rabbit_to_Leather = GetTanningLeatherWorkingSettings().RabbitToLeather;
	static float CowPelt_to_Leather = GetTanningLeatherWorkingSettings().CowPeltToLeather;
	static float PigPelt_to_Leather = GetTanningLeatherWorkingSettings().PigPeltToLeather;
	static float DeerPelt_to_Leather = GetTanningLeatherWorkingSettings().DeerPeltToLeather;
	static float GoatPelt_to_Leather = GetTanningLeatherWorkingSettings().GoatPeltToLeather;
	static float BearPelt_to_Leather = GetTanningLeatherWorkingSettings().BearPeltToLeather;
	static float SheepPelt_to_Leather = GetTanningLeatherWorkingSettings().SheepPeltToLeather;
	static float WolfPelt_to_Leather = GetTanningLeatherWorkingSettings().WolfPeltToLeather;
	static float MouflonPelt_to_Leather = GetTanningLeatherWorkingSettings().MouflonPeltToLeather;
	
	ref Timer m_TimeBeforeSmelting;
	private bool m_IsLocked = false;
	bool m_IsCurrentlySmelting = false;
	protected bool ActionCondition
	private ref Timer m_FurnaceSmeltTime;
	float Leather_Quantity = GetTannedLeather().GetQuantity();
	protected float Lock;
	

	const string ATTACHMENT_PELT_BASE			= "DryRackLeather";
	const string ATTACHMENT_PELT_TANNEDLEATHER	= "TannedLeather";
	const string ATTACHMENT_PELT_GARDENLIME		= "GardenLime";

	void DryingFrame()
	{
		m_FurnaceSmeltTime = new Timer();
		
		ShowSimpleSelection("Leather", 0);
		ShowSimpleSelection("CuredLeather", 0);
		
		RegisterNetSyncVariableBool("m_IsLocked");
	};
	
	override void EEInit()
	{
		ShowSimpleSelection("Leather", 0);
		ShowSimpleSelection("CuredLeather", 0);
	};
	
	private void ShowSimpleSelection(string selectionName, bool hide = false)
    {
        TStringArray selectionNames = new TStringArray;
        ConfigGetTextArray("simpleHiddenSelections",selectionNames);
        int selectionId = selectionNames.Find(selectionName);
        SetSimpleHiddenSelectionState(selectionId, hide);
    };
	
	bool IsLocked()
	{
		if(m_IsLocked == true)
		{
			return true;
		}
		else
		{
			return false;
		};
		SetSynchDirty();
	};

	void TimeBeforeSmelting( float actiontime)
	{
		m_TimeBeforeSmelting.Run(actiontime, this, "DoNothing", NULL, false);
	};

	bool IsItemTypeAttached( typename item_type )
	{
		if ( GetAttachmentByType( item_type ) )
		{
			return true;
		};
		return false;
	};
	//Has attachments of required quantity
	bool IsItemAttachedQuantity( typename item_type, float quantity )
	{
		ItemBase item = ItemBase.Cast( GetAttachmentByType( item_type ) );
		
		if ( item.GetQuantity() >= quantity )
		{
			return true;
		};
		
		return false;
	};

	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item,slot_name);

		if(slot_name == "DryRackLeather")
		{
			if ( item.IsKindOf("CleanedPelt_Base"))
			{
				ShowSimpleSelection("Leather", 1);
				ShowSimpleSelection("CuredLeather", 0);
			}
			else if ( item.IsKindOf("TannedLeather"))
			{
				ShowSimpleSelection("Leather", 0);
				ShowSimpleSelection("CuredLeather", 1);
			}
		}
		else if (slot_name == "Lime" && slot_name == "")
		{
			ShowSimpleSelection("Leather", 0);
			ShowSimpleSelection("CuredLeather", 0);
		};
	};
	
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		
		if(slot_name == "DryRackLeather")
		{
			if ( item.IsKindOf("CleanedPelt_Base")) // any attachment but coal
			{
				ShowSimpleSelection("Leather", 0);
				ShowSimpleSelection("CuredLeather", 0);
			}
			else if ( item.IsKindOf("TannedLeather")) // any attachment but coal
			{
				ShowSimpleSelection("CuredLeather", 0);
				ShowSimpleSelection("Leather", 0);
			};
		};
	};
	
	override bool CanPutInCargo( EntityAI parent )
    {
        if ( GetInventory().AttachmentCount() == 0)
        {
            return true;
        };
		return false;
    };
    
    override bool CanPutIntoHands(EntityAI parent)
    {
        if ( GetInventory().AttachmentCount() == 0)
        {
            return true;
        };
		return false;
    };
	
	override bool NameOverride(out string output)
	{
		if ( m_IsLocked == true )
		{
			output = "Tanning Hide"; 
			output.ToUpper();
			return true;
		};
		return false;
	};
	
	override bool DescriptionOverride(out string output)
	{
		if ( m_IsLocked == true )
		{
			output ="The pelt seems to be Tanning";
			output.ToUpper();
			return true;
		};
		return false;
	};

	void Lock(float actiontime)
	{	
		m_IsLocked = true;
		SetSynchDirty();
		m_FurnaceSmeltTime.Run(actiontime, this, "Unlock", NULL,false);
		LockLeatherSlots(true);
	};
	
	void Unlock()
	{
		m_IsLocked = false;
		SetSynchDirty();
		GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
		LockLeatherSlots(false);
		TanComplete()
	};
	
	void LockLeatherSlots(bool do_lock)
	{
		ItemBase PeltSlots = GetPeltBase();
		ItemBase LeatherSlots = GetTannedLeather();
		
		if (PeltSlots)
		{
			if (do_lock)
			{
				PeltSlots.LockToParent();
			}
			else
			{
				PeltSlots.UnlockFromParent();
			};
		};
	};

	CleanedPelt_Base GetPeltBase()
	{
		return CleanedPelt_Base.Cast( GetAttachmentByType (CleanedPelt_Base) );
	};
	CleanedWildboarPelt GetWildboarPelt()
	{
		return CleanedWildboarPelt.Cast( GetAttachmentByType (CleanedWildboarPelt) );
	};
	CleanedRabbitPelt GetRabbitPelt()
	{
		return CleanedRabbitPelt.Cast( GetAttachmentByType (CleanedRabbitPelt) );
	};
	CleanedCowPelt GetCowPelt()
	{
		return CleanedCowPelt.Cast( GetAttachmentByType (CleanedCowPelt) );
	};
	CleanedPigPelt GetPigPelt()
	{
		return CleanedPigPelt.Cast( GetAttachmentByType (CleanedPigPelt) );
	};	
	CleanedDeerPelt GetDeerPelt()
	{
		return CleanedDeerPelt.Cast( GetAttachmentByType (CleanedDeerPelt) );
	};
	CleanedGoatPelt GetGoatPelt()
	{
		return CleanedGoatPelt.Cast( GetAttachmentByType (CleanedGoatPelt) );
	};
	CleanedBearPelt GetBearPelt()
	{
		return CleanedBearPelt.Cast( GetAttachmentByType (CleanedBearPelt) );
	};
	CleanedWolfPelt GetWolfPelt()
	{
		return CleanedWolfPelt.Cast( GetAttachmentByType (CleanedWolfPelt) );
	};
	CleanedSheepPelt GetSheepPelt()
	{
		return CleanedSheepPelt.Cast( GetAttachmentByType (CleanedSheepPelt) );
	};
	CleanedMouflonPelt GetMouflonPelt()
	{
		return CleanedMouflonPelt.Cast( GetAttachmentByType (CleanedMouflonPelt) );
	};
	GardenLime GetTannedLeatherLime()
	{
		return GardenLime.Cast( GetAttachmentByType(GardenLime) );
	};
	TannedLeather GetTannedLeather()
	{
        return TannedLeather.Cast( GetAttachmentByType(TannedLeather) );
	};


/*
CleanedWildboarPelt GetWildboarPelt()
{
  if (!GetInventory())
  {
    return null;
  }

  return CleanedWildboarPelt.Cast(GetAttachmentByType(CleanedWildboarPelt));
}
*/

	
	void Tann()
	{
		ItemBase TannedGardenLime = GetTannedLeatherLime();
		ItemBase TannedLeatherQuantity = GetTannedLeather();
		if (GetWildboarPelt() && GetTannedLeatherLime().GetQuantity() >= GardenLime_Used_PerLeather * WildboarPelt_to_Leather )
		{	
			Lock(TimeTo_TanPelt_PerLeather * WildboarPelt_to_Leather );
			TannedGardenLime.AddQuantity(-GardenLime_Used_PerLeather * WildboarPelt_to_Leather);
		};
	
		if (GetRabbitPelt() && GetTannedLeatherLime().GetQuantity() >=GardenLime_Used_PerLeather * Rabbit_to_Leather ) 
		{	
			Lock(TimeTo_TanPelt_PerLeather * Rabbit_to_Leather); //Locks until procces is done # is the how it takes before unlocking.
			//300
			TannedGardenLime.AddQuantity(-GardenLime_Used_PerLeather * WildboarPelt_to_Leather);
		};
		if (GetCowPelt() && GetTannedLeatherLime().GetQuantity() >=GardenLime_Used_PerLeather * CowPelt_to_Leather ) // after the timer for attaching items is over and the requisite item is attached
		{	

			Lock(TimeTo_TanPelt_PerLeather * CowPelt_to_Leather); //Locks until procces is done # is the how it takes before unlocking.
			//3300
			TannedGardenLime.AddQuantity(-GardenLime_Used_PerLeather * CowPelt_to_Leather );
		};
		if (GetPigPelt() && GetTannedLeatherLime().GetQuantity() >=GardenLime_Used_PerLeather * PigPelt_to_Leather ) // after the timer for attaching items is over and the requisite item is attached
		{	

			Lock(TimeTo_TanPelt_PerLeather * PigPelt_to_Leather); //Locks until procces is done # is the how it takes before unlocking.
			//1800
			TannedGardenLime.AddQuantity(-GardenLime_Used_PerLeather * PigPelt_to_Leather );
		};
		if (GetDeerPelt() && GetTannedLeatherLime().GetQuantity() >=GardenLime_Used_PerLeather * DeerPelt_to_Leather  ) // after the timer for attaching items is over and the requisite item is attached
		{	

			Lock(TimeTo_TanPelt_PerLeather * DeerPelt_to_Leather); //Locks until procces is done # is the how it takes before unlocking.
			//2400
			TannedGardenLime.AddQuantity(-GardenLime_Used_PerLeather * DeerPelt_to_Leather );
		};
		if (GetGoatPelt() && GetTannedLeatherLime().GetQuantity() >=GardenLime_Used_PerLeather * GoatPelt_to_Leather  ) // after the timer for attaching items is over and the requisite item is attached
		{	

			Lock(TimeTo_TanPelt_PerLeather * GoatPelt_to_Leather); //Locks until procces is done # is the how it takes before unlocking.
			//1200
			TannedGardenLime.AddQuantity(-GardenLime_Used_PerLeather * GoatPelt_to_Leather );
		};
		if (GetBearPelt() && GetTannedLeatherLime().GetQuantity() >=GardenLime_Used_PerLeather * BearPelt_to_Leather) // after the timer for attaching items is over and the requisite item is attached
		{	

			Lock(TimeTo_TanPelt_PerLeather * BearPelt_to_Leather); //Locks until procces is done # is the how it takes before unlocking.
			//3000
			TannedGardenLime.AddQuantity(-GardenLime_Used_PerLeather * BearPelt_to_Leather);
		};
		if (GetSheepPelt() && GetTannedLeatherLime().GetQuantity() >=GardenLime_Used_PerLeather * SheepPelt_to_Leather ) // after the timer for attaching items is over and the requisite item is attached
		{	
			Lock(TimeTo_TanPelt_PerLeather * SheepPelt_to_Leather); //Locks until procces is done # is the how it takes before unlocking.
			//1200
			TannedGardenLime.AddQuantity(-GardenLime_Used_PerLeather * SheepPelt_to_Leather);
		};
		if (GetWolfPelt() && GetTannedLeatherLime().GetQuantity() >=GardenLime_Used_PerLeather * WolfPelt_to_Leather ) // after the timer for attaching items is over and the requisite item is attached
		{	

			Lock(TimeTo_TanPelt_PerLeather * WolfPelt_to_Leather); //Locks until procces is done # is the how it takes before unlocking.
			//1260
			TannedGardenLime.AddQuantity(-GardenLime_Used_PerLeather * WolfPelt_to_Leather);
		};
		if (GetMouflonPelt() && GetTannedLeatherLime().GetQuantity() >=GardenLime_Used_PerLeather * MouflonPelt_to_Leather ) // after the timer for attaching items is over and the requisite item is attached
		{	

			Lock(TimeTo_TanPelt_PerLeather * MouflonPelt_to_Leather); //Locks until procces is done # is the how it takes before unlocking.
			//1200
			TannedGardenLime.AddQuantity(-GardenLime_Used_PerLeather * MouflonPelt_to_Leather);
		};

	};
	
	void TanComplete()
	{
		ItemBase TannedGardenLime = GetTannedLeatherLime();
		ItemBase TannedLeatherQuantity = GetTannedLeather();
		if (GetWildboarPelt() && GetTannedLeatherLime().GetQuantity() >= GardenLime_Used_PerLeather * WildboarPelt_to_Leather )
		{	
			GetGame().ObjectDelete( GetWildboarPelt() );
			TannedLeather TannedLeather1 = TannedLeather.Cast(GetInventory().CreateAttachment("TannedLeather"));
			TannedLeather1.SetQuantity(WildboarPelt_to_Leather);

		};
	
		if (GetRabbitPelt() && GetTannedLeatherLime().GetQuantity() >=GardenLime_Used_PerLeather * Rabbit_to_Leather ) 
		{	
			GetGame().ObjectDelete( GetRabbitPelt() ); 
			TannedLeather TannedLeather2 = TannedLeather.Cast(GetInventory().CreateAttachment("TannedLeather"));
			TannedLeather2.SetQuantity(Rabbit_to_Leather);

		};
		if (GetCowPelt() && GetTannedLeatherLime().GetQuantity() >=GardenLime_Used_PerLeather * CowPelt_to_Leather ) // after the timer for attaching items is over and the requisite item is attached
		{	
			GetGame().ObjectDelete( GetCowPelt() ); //Deletes the zinc ore if it goes tho this IF statement GetMoltenBrass().SetQuantity( MouflonQuantity ) //sets the Brass Quantity 
			TannedLeather TannedLeather3 = TannedLeather.Cast(GetInventory().CreateAttachment("TannedLeather"));
			TannedLeather3.SetQuantity(CowPelt_to_Leather);

		};
		if (GetPigPelt() && GetTannedLeatherLime().GetQuantity() >=GardenLime_Used_PerLeather * PigPelt_to_Leather ) // after the timer for attaching items is over and the requisite item is attached
		{	
			GetGame().ObjectDelete( GetPigPelt() ); //Deletes the zinc ore if it goes tho this IF statement GetMoltenBrass().SetQuantity( MouflonQuantity ) //sets the Brass Quantity 
			TannedLeather TannedLeather4 = TannedLeather.Cast(GetInventory().CreateAttachment("TannedLeather"));
			TannedLeather4.SetQuantity(PigPelt_to_Leather);

		};
		if (GetDeerPelt() && GetTannedLeatherLime().GetQuantity() >=GardenLime_Used_PerLeather * DeerPelt_to_Leather  ) // after the timer for attaching items is over and the requisite item is attached
		{	
			GetGame().ObjectDelete( GetDeerPelt() ); //Deletes the zinc ore if it goes tho this IF statement GetMoltenBrass().SetQuantity( MouflonQuantity ) //sets the Brass Quantity 
			TannedLeather TannedLeather5 = TannedLeather.Cast(GetInventory().CreateAttachment("TannedLeather"));
			TannedLeather5.SetQuantity(DeerPelt_to_Leather);

		};
		if (GetGoatPelt() && GetTannedLeatherLime().GetQuantity() >=GardenLime_Used_PerLeather * GoatPelt_to_Leather  ) // after the timer for attaching items is over and the requisite item is attached
		{	
			GetGame().ObjectDelete( GetGoatPelt() ); //Deletes the zinc ore if it goes tho this IF statement GetMoltenBrass().SetQuantity( MouflonQuantity ) //sets the Brass Quantity 
			TannedLeather TannedLeather6 = TannedLeather.Cast(GetInventory().CreateAttachment("TannedLeather"));
			TannedLeather6.SetQuantity(GoatPelt_to_Leather);

		};
		if (GetBearPelt() && GetTannedLeatherLime().GetQuantity() >=GardenLime_Used_PerLeather * BearPelt_to_Leather) // after the timer for attaching items is over and the requisite item is attached
		{	
			GetGame().ObjectDelete( GetBearPelt() ); //Deletes the zinc ore if it goes tho this IF statement GetMoltenBrass().SetQuantity( MouflonQuantity ) //sets the Brass Quantity 
			TannedLeather TannedLeather7 = TannedLeather.Cast(GetInventory().CreateAttachment("TannedLeather"));
			TannedLeather7.SetQuantity(BearPelt_to_Leather);

		};
		if (GetSheepPelt() && GetTannedLeatherLime().GetQuantity() >=GardenLime_Used_PerLeather * SheepPelt_to_Leather ) // after the timer for attaching items is over and the requisite item is attached
		{	
			GetGame().ObjectDelete( GetSheepPelt() ); //Deletes the zinc ore if it goes tho this IF statement GetMoltenBrass().SetQuantity( MouflonQuantity ) //sets the Brass Quantity 
			TannedLeather TannedLeather8 = TannedLeather.Cast(GetInventory().CreateAttachment("TannedLeather"));
			TannedLeather8.SetQuantity(SheepPelt_to_Leather);

		};
		if (GetWolfPelt() && GetTannedLeatherLime().GetQuantity() >=GardenLime_Used_PerLeather * WolfPelt_to_Leather ) // after the timer for attaching items is over and the requisite item is attached
		{	
			GetGame().ObjectDelete( GetWolfPelt() ); //Deletes the zinc ore if it goes tho this IF statement GetMoltenBrass().SetQuantity( MouflonQuantity ) //sets the Brass Quantity 
			TannedLeather TannedLeather9 = TannedLeather.Cast(GetInventory().CreateAttachment("TannedLeather"));
			TannedLeather9.SetQuantity(WolfPelt_to_Leather);

		};
		if (GetMouflonPelt() && GetTannedLeatherLime().GetQuantity() >=GardenLime_Used_PerLeather * MouflonPelt_to_Leather ) // after the timer for attaching items is over and the requisite item is attached
		{	
			GetGame().ObjectDelete( GetMouflonPelt() ); //Deletes the zinc ore if it goes tho this IF statement GetMoltenBrass().SetQuantity( MouflonQuantity ) //sets the Brass Quantity 
			TannedLeather TannedLeather10 = TannedLeather.Cast(GetInventory().CreateAttachment("TannedLeather"));
			TannedLeather10.SetQuantity(MouflonPelt_to_Leather);
		};

	};
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
    {
        super.OnPlacementComplete( player, position, orientation );
            
        SetIsPlaceSound( true );
    };
	
	override string GetPlaceSoundset()
	{
		return "placeBarrel_SoundSet";
	};
	


	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionTannLeather);
		AddAction(ActionAttach);
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}
	
};