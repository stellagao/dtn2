#!/bin/bash

this_dir=`pwd`

help(){
	echo "this bash's help:"
	echo "with no argument :"
	echo "./dtn-control.sh : help" 

	echo "with 1 argument :"
	echo "./dtn-control.sh -help: help"
	echo "./dtn-control.sh -iaodv: inmod iaodv.ko"
	echo "./dtn-control.sh -dtnNodeName: look for dtn node's name"
	echo "./dtn-control.sh -realSimulator: open realSimulator"
	echo "./dtn-control.sh -mapInterface: open mapInterface"
	echo "./dtn-control.sh -osm2Sqlite: open osm2Sqlite and produce sumo.db"
	echo "./dtn-control.sh -dtn2: open dtn2"
	echo "./dtn-control.sh -clearData: clear log and historyarea law and neighbour historyarea law,if you want to change 			frequency vector's type,you must carry out this first"
	echo "with 2 or more arguments :"
	echo "./dtn-control.sh -renameDevices : rename the dtn node's name"
	echo "./dtn-control.sh -modifyVector : modify frequency vector's type,options [minute | hour | monafteve | week | month]
		for example, ./dtn-control.sh -modifyVector minute hour week"

	}
#find node's name from /etc/dtn.conf
cd ./NodeName/FindDtnNodeName
node_name=`./FindDtnNodeName`

temp=${node_name##*//}
node_ip=${temp%.gao*}

cd $this_dir
#no argument
if [ $# -eq 0 ];then
	help

elif [ $# -eq 1 ];then
	if [ $1 = "-help" ];then
		help
	elif [ $1 = "-iaodv"	];then
		#inmod iaodv.ko
		cd ./iaodv
		./aodv.sh $node_ip
		cd $this_dir

	elif [ $1 = "-dtnNodeName" ];then
		#look for dtn node's name
		echo $node_name

	elif [ $1 = "-realSimulator" ];then
		#open osm2Sqlite and produce sumo.db
		cd ./RealSimulator
		gnome-terminal -x bash -c "./RealSimulator"
		cd $this_dir

	elif [ $1 = "-mapInterface" ];then
		#open mapInterface
		cd ./MapInterface
		gnome-terminal -x bash -c "./MapInterface"
		cd $this_dir

	elif [ $1 = "-osm2Sqlite" ];then
		#open osm2Sqlite and produce sumo.db
		cd ./Osm2Sqlite
		./Osm2Sqlite
		cd $this_dir

	elif [ $1 = "-dtn2" ];then
		#open dtn2
		cd ./DTN/DTN2/daemon
		gnome-terminal -x bash -c "./dtnd"
		cd $this_dir

	elif [ $1 = "-clearData" ];then
		#open dtn2
		cd ./DTN/DTN2/logDocuments
		rm -rf areamoving.txt
		rm -rf GeohistoryLog.txt
		rm -rf historyarea.txt
		rm -rf geoHistory_dtn
		cd $this_dir
	else
	     echo "error : wrong arguments"
	     help
	fi

elif [ $# -eq 2 ];then
	if [ $1 = "-renameDevices" ];then
		cd ./NodeName/ModifyDtnNodeName
		./ModifyDtnNodeName $2	
		cd $this_dir

	elif [ $1 = "-modifyVector" ];then
		#modify frequency vector's type
		cd ./ModifyVector
		./ModifyVector $*
		cd $this_dir

	else
		echo "error : wrong arguments"	
		help
	fi

elif [ $# -ge 2 ];then

	if [ $1 = "-modifyVector" ];then
		#modify frequency vector's type
		cd ./ModifyVector
		./ModifyVector $*
		cd $this_dir

	else
		echo "error : wrong arguments"	
		help
	fi
else

	help
fi