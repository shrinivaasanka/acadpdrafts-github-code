#*****************************************************************************************/
#acadpdrafts - My academic publication drafts and related documents including ID Proofs
#
#This program is free software: you can redistribute it and/or modify
#it under the terms of the GNU General Public License as published by
#the Free Software Foundation, either version 3 of the License, or
#(at your option) any later version.
#
#This program is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#GNU General Public License for more details.
#
#You should have received a copy of the GNU General Public License
#along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
#--------------------------------------------------------------------------------------------------
#Srinivasan Kannan (alias) Ka.Shrinivaasan (alias) Shrinivas Kannan
#Independent Open Source Developer, Researcher and Consultant
#Ph: 9789346927, 9003082186, 9791165980
#Open Source Products Profile(Krishna iResearch): http://sourceforge.net/users/ka_shrinivaasan, http://www.ohloh.net/accounts/ka_shrinivaasan
#Personal website(research): https://sites.google.com/site/kuja27/
#emails: ka.shrinivaasan@gmail.com, shrinivas.kannan@gmail.com, kashrinivaasan@live.com
#--------------------------------------------------------------------------------------------------
#*****************************************************************************************/


#!/bin/bash
#wget -rc http://sourceforge.net/projects/acadpdrafts/files/index.html
grep "a href=\"http" sourceforge.net/projects/acadpdrafts/files/index.html|grep acadpdrafts | awk -F"=" '{print $2}' | xargs wget -rc

