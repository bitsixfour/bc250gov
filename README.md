
This is a power manager/governor for the AMD BC-250 (Cyan Skillfish). It watches GPU activity and temperature but then it tells the SMU to go through hard-coded clock and voltage points.\
Thank you to existing documentation for already exploring many of the SMU functions which are undocumented on the bios v3 version. 

This...
- only targets the BC-250
- samples GPU activity and temperature while it runs
- backs off when the GPU is idle and drops to a lower point when things get too hot
- talks directly to PCI config space and DRM


## try it

You need the BC-250 SoC. They have gotten way more expensive as I bought mine for 50 dollars on eBay. You also need the development dependencies from `shell.nix`, and permission to access the GPU and PCI config space. 

```sh
nix-shell
```

Build the executable from the repository, then run it as root:

```sh
sudo ./bc250gov
```



## need to know
- pts are hard-coded for now; Cpp doesn't have a nice enough library like Rust (imho) for simple yaml. It /should/ be fine
- the project is focused on efficiency rather than performance for server use
- if something goes wrong, you should pkill (WOW!)


## Notice

This is at your own risk, but this is just for personal use and a fun project.
