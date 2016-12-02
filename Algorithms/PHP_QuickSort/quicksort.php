<?php 

$myrandomarray = new randomArray(100);

$myrandomarray->printArray();

$myrandomarray->quicksort();

$myrandomarray->printArray();

/*** CLASS ***/

class randomArray
{
	public $nums;

	public function __construct($size)
	{	
		$this->nums = array();

		if($size > 0)
		{
			$i = 0;
			while($i < $size)
			{
				$this->nums[] = rand(0,999);
				$i++;
			}
		}
		else
		{
			echo "bad constructor argument\n";
		}
	}	#END size constructor

	public function printArray()
	{
		echo "\nArray Size: ".count($this->nums)."\n";
		$counter = 0;
		foreach ($this->nums as $n)
		{
			echo $n." ";

			if ($counter % 10 == 9)
			{
				echo "\n";
			}
			$counter++;
		}
	}	#END printArray

	public function quicksort()
	{
		function quicksortHelper(&$arr, $left, $right)
		{
			$l = $left;
			$r = $right;
			
			$pivot = $arr[($left + $right)/2];		

			while ($l <= $r)
			{
				while ($arr[$l] < $pivot)
				{
					$l++;
				}
				while ($arr[$r] > $pivot)
				{
					$r--;
				}
				if ($l <= $r)
				{
					$temp = $arr[$l];
					$arr[$l] = $arr[$r];
					$arr[$r] = $temp;
					$l++;
					$r--;
				}
			}

			if ($left < $l)
			{
				quicksortHelper($arr, $left, $r);
			}
			if ($right > $r)
			{
				quicksortHelper($arr, $l, $right);
			}
		}
		quicksortHelper($this->nums, 0, count($this->nums)-1);
	}	
}	#END class randomArray
?>