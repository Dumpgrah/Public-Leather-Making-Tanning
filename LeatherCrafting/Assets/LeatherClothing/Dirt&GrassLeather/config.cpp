class CfgPatches
{
	class Dirt_Grass_Leather
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Characters_Tops","DZ_Gear_Cultivation"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Clothing;
	class LeatherJacket_ColorBase;
	class LeatherPants_ColorBase;
	class LeatherGloves_ColorBase;
	class LeatherHat_ColorBase;
	class LeatherStorageVest_ColorBase;
	class PlantMaterial;
	class DirtyGrassPlantMaterial: PlantMaterial
	{
		scope = 2;
		displayName = "Dirty Plant Material";
		descriptionShort = "Plant Material with mud all over it";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"LeatherCrafting\Assets\LeatherClothing\Data\DGPlantMaterial_Color.paa"};
		hiddenSelectionsMaterials[] = {"LeatherCrafting\Assets\LeatherClothing\Data\DGplant_material.rvmat"};
	};
	class LeatherJacket_DirtyGrass: LeatherJacket_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = 
		{
			"LeatherCrafting\Assets\LeatherClothing\Dirt&GrassLeather\Shirt\Shirt_Color.paa",
			"LeatherCrafting\Assets\LeatherClothing\Dirt&GrassLeather\Shirt\Shirt_Color.paa",
			"LeatherCrafting\Assets\LeatherClothing\Dirt&GrassLeather\Shirt\Shirt_Color.paa"
		};
		hiddenSelectionsMaterials[] = 
		{
			"LeatherCrafting\Assets\LeatherClothing\Dirt&GrassLeather\Shirt\Top_LeatherJacket_DirtyGrass.rvmat","LeatherCrafting\Assets\LeatherClothing\Dirt&GrassLeather\Shirt\Top_LeatherJacket_DirtyGrass.rvmat","LeatherCrafting\Assets\LeatherClothing\Dirt&GrassLeather\Shirt\Top_LeatherJacket_DirtyGrass.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1,{"DZ\characters\tops\data\Top_LeatherJacket_DirtyGrass.rvmat","DZ\characters\tops\data\Top_LeatherJacket_DirtyGrass.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\tops\Data\Top_LeatherJacket_DirtyGrass.rvmat","DZ\characters\tops\Data\Top_LeatherJacket_DirtyGrass.rvmat"}},{0.3,{}},{0,{"DZ\characters\tops\Data\Top_LeatherJacket_DirtyGrass.rvmat","DZ\characters\tops\Data\Top_LeatherJacket_DirtyGrass.rvmat"}}};
				};
			};
			class GlobalArmor{};
		};
	};
	class LeatherPants_DirtyGrass: LeatherPants_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"LeatherCrafting\Assets\LeatherClothing\Dirt&GrassLeather\Pants\Pants_Color.paa","LeatherCrafting\Assets\LeatherClothing\Dirt&GrassLeather\Pants\Pants_Color.paa","LeatherCrafting\Assets\LeatherClothing\Dirt&GrassLeather\Pants\Pants_Color.paa"};
		hiddenSelectionsMaterials[] = {"LeatherCrafting\Assets\LeatherClothing\Dirt&GrassLeather\Pants\Top_LeatherPants_DirtyGrass.rvmat","LeatherCrafting\Assets\LeatherClothing\Dirt&GrassLeather\Pants\Top_LeatherPants_DirtyGrass.rvmat","LeatherCrafting\Assets\LeatherClothing\Dirt&GrassLeather\Pants\Top_LeatherPants_DirtyGrass.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1,{"DZ\characters\tops\data\Top_LeatherJacket_DirtyGrass.rvmat","DZ\characters\tops\data\Top_LeatherJacket_DirtyGrass.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\tops\Data\Top_LeatherJacket_DirtyGrass.rvmat","DZ\characters\tops\Data\Top_LeatherJacket_DirtyGrass.rvmat"}},{0.3,{}},{0,{"DZ\characters\tops\Data\Top_LeatherJacket_DirtyGrass.rvmat","DZ\characters\tops\Data\Top_LeatherJacket_DirtyGrass.rvmat"}}};
				};
			};
			class GlobalArmor{};
		};
	};
	class LeatherGloves_DirtyGrass: LeatherGloves_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"LeatherCrafting\Assets\LeatherClothing\Dirt&GrassLeather\Gloves\Gloves_Color.paa","LeatherCrafting\Assets\LeatherClothing\Dirt&GrassLeather\Gloves\Gloves_Color.paa","LeatherCrafting\Assets\LeatherClothing\Dirt&GrassLeather\Gloves\Gloves_Color.paa"};
		hiddenSelectionsMaterials[] = {"LeatherCrafting\Assets\LeatherClothing\Dirt&GrassLeather\Gloves\Top_LeatherGloves_DirtyGrass.rvmat","LeatherCrafting\Assets\LeatherClothing\Dirt&GrassLeather\Gloves\Top_LeatherGloves_DirtyGrass.rvmat","LeatherCrafting\Assets\LeatherClothing\Dirt&GrassLeather\Gloves\Top_LeatherGloves_DirtyGrass.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1,{"DZ\characters\tops\data\Top_LeatherJacket_DirtyGrass.rvmat","DZ\characters\tops\data\Top_LeatherJacket_DirtyGrass.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\tops\Data\Top_LeatherJacket_DirtyGrass.rvmat","DZ\characters\tops\Data\Top_LeatherJacket_DirtyGrass.rvmat"}},{0.3,{}},{0,{"DZ\characters\tops\Data\Top_LeatherJacket_DirtyGrass.rvmat","DZ\characters\tops\Data\Top_LeatherJacket_DirtyGrass.rvmat"}}};
				};
			};
			class GlobalArmor{};
		};
	};
	class LeatherVest_DirtyGrass: LeatherStorageVest_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = 
		{
			"LeatherCrafting\Assets\LeatherClothing\Dirt&GrassLeather\Vest\Vest_Color.paa",
			"LeatherCrafting\Assets\LeatherClothing\Dirt&GrassLeather\Vest\Vest_Color.paa",
			"LeatherCrafting\Assets\LeatherClothing\Dirt&GrassLeather\Vest\Vest_Color.paa"
		};
		hiddenSelectionsMaterials[] = {"LeatherCrafting\Assets\LeatherClothing\Dirt&GrassLeather\Vest\Top_LeatherVest_DirtyGrass.rvmat","LeatherCrafting\Assets\LeatherClothing\Dirt&GrassLeather\Vest\Top_LeatherVest_DirtyGrass.rvmat","LeatherCrafting\Assets\LeatherClothing\Dirt&GrassLeather\Vest\Top_LeatherVest_DirtyGrass.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1,{"DZ\characters\tops\data\Top_LeatherJacket_DirtyGrass.rvmat","DZ\characters\tops\data\Top_LeatherJacket_DirtyGrass.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\tops\Data\Top_LeatherJacket_DirtyGrass.rvmat","DZ\characters\tops\Data\Top_LeatherJacket_DirtyGrass.rvmat"}},{0.3,{}},{0,{"DZ\characters\tops\Data\Top_LeatherJacket_DirtyGrass.rvmat","DZ\characters\tops\Data\Top_LeatherJacket_DirtyGrass.rvmat"}}};
				};
			};
			class GlobalArmor{};
		};
	};
};
