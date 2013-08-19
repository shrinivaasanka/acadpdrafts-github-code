#!/bin/bash
rsync -avz --progress -e ssh $1 ka_shrinivaasan@frs.sourceforge.net:/home/frs/project/acadpdrafts/files
