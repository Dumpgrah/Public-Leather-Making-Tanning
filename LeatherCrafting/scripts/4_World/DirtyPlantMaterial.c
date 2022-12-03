modded class PlantMaterial
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionDirtyPlant);

	}
	override void Open()
	{
		ReplaceEdibleWithNew("DirtyGrassPlantMaterial");
	}

	
	void ReplaceEdibleWithNew (string typeName)
	{
		PlayerBase player = PlayerBase.Cast(GetHierarchyRootPlayer());
		if (player)
		{
			ReplaceEdibleWithNewLambda lambda = new ReplaceEdibleWithNewLambda(this, typeName, player);
			player.ServerReplaceItemInHandsWithNew(lambda);
		}
		else
			Error("ReplaceEdibleWithNew - cannot use edible without player");
	}
};
class DirtyGrassPlantMaterial:PlantMaterial
{
	override void SetActions()
	{
		super.SetActions();
		
		RemoveAction(ActionDirtyPlant);

	}

};