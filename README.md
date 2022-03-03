# Antartic-Operating-System
The Antartic OS writen in asm and C
# Building
If you want to build it install docker<br/>
then type in cmd or terminal<br/>
<br/>
`docker build buildenv -t aos-buildenv`<br/>
<br/>
and while you are in the dirrectory of the os<br/>
type (If you are on windows command prompt)<br/>
`docker run --rm -it -v "%cd%":/root/env aos-buildenv`<br/>
for linux and macOS type<br/>
`docker run --rm -it -v "$(pwd)":/root/env myos-buildenv`
<br/>
then after that do `make os`<br/>
then in the `dist/x86_64` foulder you will have the iso file
