class ActionTannLeather: ActionInteractBase
{	
	void ActionTannLeather()
	{
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask        = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
	}

	override string GetText()
	{
		return "Start Tanning";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		static float GardenLime_Used_PerLeather = GetTanningLeatherWorkingSettings().GardenLimeUsedPerLeather;
		
		
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );
		Object target_object = target.GetObject();
		string selection = target_object.GetActionComponentName( target.GetComponentIndex() );
		TannedLeather Leather = TannedLeather.Cast( target_entity.GetAttachmentByType(TannedLeather) );
		GardenLime Lime = GardenLime.Cast( target_entity.GetAttachmentByType(GardenLime) );
		DryingFrame frame = DryingFrame.Cast( target.GetObject() );
		
		if (!frame.IsLocked() && !Leather && target_entity.FindAttachmentBySlotName("DryRackLeather") && Lime && Lime.GetQuantity() >= GardenLime_Used_PerLeather )
		{
			return true;
		}
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		DryingFrame LeatherCuring = DryingFrame.Cast( action_data.m_Target.GetObject() );
		LeatherCuring.Tann();
	}
}