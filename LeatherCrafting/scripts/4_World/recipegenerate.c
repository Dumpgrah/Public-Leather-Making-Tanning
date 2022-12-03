modded class PluginRecipesManager 
{

 	override void RegisterRecipies()
	{
		super.RegisterRecipies();
		///Leather Crafting
		RegisterRecipe(new CraftCleanedPeltWildBoar);
		RegisterRecipe(new CraftCleanedPeltRabbit);
		RegisterRecipe(new CraftCleanedPeltCow);
		RegisterRecipe(new CraftCleanedPeltPig);
		RegisterRecipe(new CraftCleanedPeltDeer);
		RegisterRecipe(new CraftCleanedPeltGoat);
		RegisterRecipe(new CraftCleanedPeltBear);
		RegisterRecipe(new CraftCleanedPeltWolf);
		RegisterRecipe(new CraftCleanedPeltSheep);
		RegisterRecipe(new CraftCleanedPeltMouflon);
		
		RegisterRecipe(new DismantleFrame);
		RegisterRecipe(new CraftHookAndRope);
		RegisterRecipe(new CraftUnfinishedDryingFrame);
		RegisterRecipe(new CraftDryingFrame);
		RegisterRecipe(new CraftLeatherHat);
		RegisterRecipe(new CraftLeatherJacket);
		RegisterRecipe(new CraftLeatherVest);
		RegisterRecipe(new CraftLeatherGloves);
		RegisterRecipe(new CraftLeatherPants);
		RegisterRecipe(new CraftLeatherPouch);
		RegisterRecipe(new CraftLeatherShoes);
		RegisterRecipe(new CreateDirtyGrassLeatherJacket);
		RegisterRecipe(new CreateDirtyGrassLeatherPants);
		RegisterRecipe(new CreateDirtyGrassLeatherVest);
		RegisterRecipe(new CreateDirtyGrassLeatherGloves);
		
		RegisterRecipe(new CreateBloodyLeatherJacket);
		RegisterRecipe(new CreateBloodyLeatherPants);
		RegisterRecipe(new CreateBloodyLeatherVest);
		RegisterRecipe(new CreateBloodyLeatherGloves);
		
		RegisterRecipe(new SitchChestHolster);
		RegisterRecipe(new SitchPistolHolster);
		RegisterRecipe(new SitchSawedOffHolster);


    }
};

