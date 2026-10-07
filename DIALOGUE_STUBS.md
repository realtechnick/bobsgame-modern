# Empty Dialogue Stub Catalog
Every NPC interaction below has a **working action prompt** but an **empty dialogue window** — Bob wired the prompt, placed the character, and never wrote the lines. Generated from source 2026-10-07.
**183 stubs** across 42 files. Bob's TODO notes are quoted verbatim where he left them.
Location given as `file:line` in `src/gamelogic/`.

## Town

### Arcade — `TOWNArcade` (1 stub)
- **"Redeem Tickets"** — `arcadeguy_npc` — Bob's note: *"TODO: ticket thing"* — `town/arcade.cpp:64`

### Beautysalon — `TOWNBeautySalon` (2 stubs)
- **"Get A Haircut"** — `counterguy_npc` — Bob's note: *"TODO: get haircut"* — `town/beautysalon.cpp:68`
- **"Get A Tan"** — `tanningcounterguy_npc` — Bob's note: *"TODO: get a tan"* — `town/beautysalon.cpp:89`

### Bookstore — `TOWNBookstore` (1 stub)
- **"Buy Books"** — `counterguy_npc` — Bob's note: *"TODO: buy books"* — `town/bookstore.cpp:51`

### Coffeeshop — `TOWNCoffeeShop` (1 stub)
- **"Buy Coffee"** — `counterguy_npc` — `town/coffeeshop.cpp:105`

### Crazyladyhouse — `TOWNCRAZYDownstairs` (2 stubs)
- **"Talk To Crazy Lady"** — `crazylady_npc` — `town/crazyladyhouse.cpp:71`
- **"Talk To Kid"** — `scrawnykid_npc` — `town/crazyladyhouse.cpp:376`

### Departmentstore — `TOWNDepartmentStore` (2 stubs)
- **"Talk To Electronics Salesman"** — `deptelecguy_npc` — Bob's note: *"TODO: buy ???"* — `town/departmentstore.cpp:90`
- **"Talk To Jewelry Salesman"** — `deptjewelryguy_npc` — Bob's note: *"TODO: buy jewelry"* — `town/departmentstore.cpp:110`

### Doctorsoffice — `TOWNDoctorsOfficeEntrance` (2 stubs)
- **"Make Appointment"** — `receptionist_npc` — `town/doctorsoffice.cpp:50`
- **"Talk To Nurse"** — `receptionist_npc` — `town/doctorsoffice.cpp:160`

### Electronicsstore — `TOWNElectronicsStore` (2 stubs)
- **"Buy Electronics"** — `counterguy_npc` — Bob's note: *"TODO: buy electronics"* — `town/electronicsstore.cpp:61`
- **"Talk To Shady Guy"** — `shadyguy_npc` — Bob's note: *"TODO: buy electronics"* — `town/electronicsstore.cpp:151`

### Friendshouse — `TOWNFRIENDDownstairs` (5 stubs)
- **"Talk To Friend's Dad"** — `friendsdad_npc` — `town/friendshouse.cpp:71`
- **"Talk To Friend's Mom"** — `friendsmom_npc` — `town/friendshouse.cpp:93`
- **"Talk To Friend's Sister"** — `friendssister_npc` — `town/friendshouse.cpp:272`
- **"Talk To Friend's Lazy Uncle"** — `sleazyunclebob_npc` — `town/friendshouse.cpp:428`
- **"Check Out Conversion Van"** — `PLAYER_npc` — `town/friendshouse.cpp:483`

### Gasstation — `TOWNGasStation` (3 stubs)
- **"Buy Expired Balogna"** — `gasstationclerk_npc` — Bob's note: *"TODO: buy balogna"* — `town/gasstation.cpp:52`
- **"Talk To Hungry Customer"** — `grinderguy_npc` — Bob's note: *"TODO: get balogna, cant leave unless buy it or put it back"* — `town/gasstation.cpp:72`
- **"Talk To Thirsty Customer"** — `coolerguy_npc` — `town/gasstation.cpp:92`

### Grocerystore — `TOWNGroceryStore` (1 stub)
- **"Buy Meat"** — `deliguy_npc` — Bob's note: *"TODO: buy meat"* — `town/grocerystore.cpp:61`

### Movietheater — `TOWNMovieTheatreMainHall` (10 stubs)
- **"Waste Money"** — `candycounter_npc` — `town/movietheater.cpp:312`
- **"Buy Candy"** — `candycounter2_npc` — `town/movietheater.cpp:331`
- **"Buy Popcorn"** — `candycounter3_npc` — `town/movietheater.cpp:350`
- **"Buy Concessions"** — `candycounter4_npc` — `town/movietheater.cpp:369`
- **"Talk To Pooping Man"** — `stallguy1_npc` — `town/movietheater.cpp:507`
- **"Talk To Pooping Man"** — `stallguy2_npc` — `town/movietheater.cpp:536`
- **"Talk To Peeing Man"** — `stallguy2_npc` — `town/movietheater.cpp:558`
- **"Talk To Freshening Up Woman"** — `stallgirl1_npc` — `town/movietheater.cpp:621`
- **"Talk To Checking Make-Up Woman"** — `stallgirl2_npc` — `town/movietheater.cpp:650`
- **"Talk To Powdering Nose Woman"** — `stallgirl3_npc` — `town/movietheater.cpp:679`

### Petstore — `TOWNPets4Less` (1 stub)
- **"Buy Pet"** — `counterguy_npc` — Bob's note: *"TODO: buy pet"* — `town/petstore.cpp:64`

### Pizzaplace — `TOWNPizzaPlace` (1 stub)
- **"Buy Pizza"** — `counterguy_npc` — Bob's note: *"TODO: buy pizza."* — `town/pizzaplace.cpp:40`

### Playground — `SCHOOLPlayground` (12 stubs)
- **"Talk To Tube Kid"** — `pipe_npc` — `town/playground.cpp:145`
- **"Talk To King Of The Hill"** — `hill_npc` — `town/playground.cpp:167`
- **"Talk To Pull-Up Bar Kid"** — `pullup_npc` — `town/playground.cpp:194`
- **"Talk To Swing Kid"** — `swingkid1_npc` — `town/playground.cpp:224`
- **"Talk To See-Saw Kid"** — `seesawkid1_npc` — `town/playground.cpp:253`
- **"Talk To See-Saw Kid"** — `seesawkid2_npc` — `town/playground.cpp:274`
- **"Talk To Tire Swing Kid"** — `tireswing_npc` — `town/playground.cpp:296`
- **"Talk To Bouncy Turtle Kid"** — `bouncyturtle_npc` — `town/playground.cpp:318`
- **"Talk To Jungle Gym Kid"** — `junglegym_npc` — `town/playground.cpp:450`
- **"Talk To Slide Kid"** — `slide_npc` — `town/playground.cpp:478`
- **"Talk To Slide Kid"** — `slide2_npc` — `town/playground.cpp:506`
- **"Talk To Swing Kid"** — `sideswing_npc` — `town/playground.cpp:529`

### Recordstore — `TOWNRecordStore` (1 stub)
- **"Buy Music"** — `counterguy_npc` — Bob's note: *"TODO: buy music"* — `town/recordstore.cpp:65`

### School — `SCHOOLGirlsBathroom` (6 stubs)
- **"Talk To Freshening Up Girl"** — `stallgirl1_npc` — `town/school.cpp:1180`
- **"Talk To Powdering Nose Girl"** — `stallgirl2_npc` — `town/school.cpp:1209`
- **"Talk To Checking Makeup Girl"** — `stallgirl3_npc` — `town/school.cpp:1238`
- **"Talk To Pooping Boy"** — `stallboy1_npc` — `town/school.cpp:1307`
- **"Talk To Pooping Boy"** — `stallboy2_npc` — `town/school.cpp:1336`
- **"Talk To Pooping Boy"** — `stallboy3_npc` — `town/school.cpp:1365`

### Tacoburger — `TOWNTacoBurger` (3 stubs)
- **"Order TacoBurgers"** — `fastfood1_npc` — Bob's note: *"TODO: buy ???"* — `town/tacoburger.cpp:57`
- **"Place Order"** — `fastfood2_npc` — Bob's note: *"TODO: buy ???"* — `town/tacoburger.cpp:77`
- **"Purchase Delicious TacoBurgers"** — `fastfood3_npc` — Bob's note: *"TODO: buy ???"* — `town/tacoburger.cpp:97`

### Videostore — `TOWNVideoRent` (1 stub)
- **"Rent Video"** — `counterguy_npc` — Bob's note: *"TODO: rent video"* — `town/videostore.cpp:66`

## City

### Apartment — `CITYNeighborAptbobsgame` (4 stubs)
- **"Talk To Neighbor"** — `neighbor_npc` — `city/apartment.cpp:679`
- **"Talk To Apartment Manager"** — `apartmentmanager_npc` — Bob's note: *"TODO: rent apartment. get shown exercise room. get shown model."* — `city/apartment.cpp:769`
- **"Check Bathroom Door"** — `PLAYER_npc` — `city/apartment.cpp:779`
- **"Check Exercise Room"** — `PLAYER_npc` — `city/apartment.cpp:786`

### Bank — `CITYBankEntrance` (9 stubs)
- **"Talk To Suzanne"** — `teller1_npc` — `city/bank.cpp:55`
- **"Talk To Diane"** — `teller2_npc` — `city/bank.cpp:74`
- **"Talk To Tina"** — `teller3_npc` — `city/bank.cpp:93`
- **"Talk To Barbara"** — `teller4_npc` — `city/bank.cpp:112`
- **"Talk To Cheryl"** — `teller5_npc` — `city/bank.cpp:131`
- **"Talk To Loan Specialist"** — `loanrep_npc` — Bob's note: *"TODO: sit down in chair"* — `city/bank.cpp:152`
- **"Talk To Security Guard"** — `security_npc` — `city/bank.cpp:173`
- **"Talk To Secretary"** — `banksecretary_npc` — Bob's note: *"TODO: need phone ringing a lot if you get close"* — `city/bank.cpp:334`
- **"Talk To Bank President"** — `bigwig_npc` — Bob's note: *"TODO: sit in chair"* — `city/bank.cpp:358`

### Casino — `CITYCasinoEntrance` (10 stubs)
- **"Talk To Casino Clerk"** — `clerk1` — `city/casino.cpp:67`
- **"Talk To Casino Clerk"** — `clerk2` — `city/casino.cpp:103`
- **"Talk To Casino Clerk"** — `clerk3` — `city/casino.cpp:139`
- **"Talk To Casino Clerk"** — `clerk4` — `city/casino.cpp:175`
- **"Talk To Cashier"** — `cashier_npc` — `city/casino.cpp:659`
- **"Talk To Bunny Girl"** — `bunnygirl1_npc` — `city/casino.cpp:707`
- **"Talk To Bunny Girl"** — `bunnygirl2_npc` — `city/casino.cpp:753`
- **"Talk To Crime Organization Team Leader"** — `crimeboss_npc` — `city/casino.cpp:854`
- **"Talk To Crime Organization Associate"** — `mafiaguy1_npc` — `city/casino.cpp:891`
- **"Talk To Crime Organization Associate"** — `mafiaguy2_npc` — `city/casino.cpp:925`

### Hall — `CITYCityHallEntrance` (8 stubs)
- **"Talk To Guard"** — `cityhallguard_npc` — `city/cityhall.cpp:67`
- **"Talk To Sitting Person"** — `sittingperson_npc` — `city/cityhall.cpp:100`
- **"Look At Bust"** — `PLAYER_npc` — `city/cityhall.cpp:199`
- **"Look At Bust"** — `PLAYER_npc` — `city/cityhall.cpp:207`
- **"Look At 1910 Portrait"** — `PLAYER_npc` — `city/cityhall.cpp:215`
- **"Look At 1940 Portrait"** — `PLAYER_npc` — `city/cityhall.cpp:223`
- **"Look At 1970 Portrait"** — `PLAYER_npc` — `city/cityhall.cpp:231`
- **"Look At 2000 Portrait"** — `PLAYER_npc` — Bob's note: *"TODO: fountain sound"* — `city/cityhall.cpp:239`

### Deli — `CITYDeli` (1 stub)
- **"Talk To Sandwich Technician"** — `deliclerk_npc` — `city/deli.cpp:135`

### Elevatedlifeplace — `CITYElevatedLifeplace` (1 stub)
- **"Talk To Apartment Manager"** — `manager_npc` — `city/elevatedlifeplace.cpp:59`

### Fashionstore — `CITYFashionStore` (2 stubs)
- **"Talk To Fashion Clerk"** — `clerk_npc` — `city/fashionstore.cpp:54`
- **"Talk To Nude Person"** — `naked_npc` — `city/fashionstore.cpp:264`

### Firestation — `CITYFireDepartmentGarage` (5 stubs)
- **"Talk To Fire Chief"** — `firedeptclerk_npc` — `city/firestation.cpp:69`
- **"Talk To Radio Guy"** — `radioguy_npc` — `city/firestation.cpp:96`
- **"Wake Up Firefighter"** — `sleepingff_npc` — Bob's note: *"TODO: snoring sound"* — `city/firestation.cpp:309`
- **"Talk To Showering Firefighter"** — `showeringff_npc` — `city/firestation.cpp:385`
- **"Talk To Pooping Firefighter"** — `poopingfireman_npc` — `city/firestation.cpp:414`

### Groovyclub — `CITYGroovyClubEntrance` (3 stubs)
- **"Purchase Ticket"** — `groovyticketguy_npc` — Bob's note: *"TODO: buy a ticket in"* — `city/groovyclub.cpp:45`
- **"Talk To Bouncer"** — `groovybouncer_npc` — Bob's note: *"TODO: need bouncer sprite"* — `city/groovyclub.cpp:67`
- **"Talk To DJ"** — `groovydj_npc` — Bob's note: *"TODO: need dj sprite"* — `city/groovyclub.cpp:169`

### Hospital — `CITYHospitalEntrance` (24 stubs)
- **"Talk To Nurse"** — `nurse1_npc` — `city/hospital.cpp:91`
- **"Talk To Nurse"** — `nurse2_npc` — `city/hospital.cpp:112`
- **"Talk To Pooping Man"** — `stallman_npc` — `city/hospital.cpp:240`
- **"Talk To Outpatient Nurse"** — `outpatientnurse_npc` — `city/hospital.cpp:450`
- **"Talk To Pooping Man"** — `stallman_npc` — `city/hospital.cpp:589`
- **"Talk To Sexy Lady"** — `stallwoman_npc` — `city/hospital.cpp:651`
- **"Talk To Visitor"** — `visitor_npc` — `city/hospital.cpp:711`
- **"Talk To Patient"** — `patient1_npc` — `city/hospital.cpp:736`
- **"Talk To Patient"** — `patient2_npc` — `city/hospital.cpp:759`
- **"Talk To Surgeon"** — `surgeon_npc` — `city/hospital.cpp:882`
- **"Talk To Patient"** — `diseased_npc` — `city/hospital.cpp:903`
- **"Talk To Assistant"** — `surgerynurse1_npc` — `city/hospital.cpp:929`
- **"Talk To Assistant"** — `surgerynurse2_npc` — `city/hospital.cpp:955`
- **"Talk To Fish Watcher"** — `crazylookingatfish_npc` — `city/hospital.cpp:1071`
- **"Talk To Psychiatrist"** — `psychiatrist_npc` — `city/hospital.cpp:1094`
- **"Talk To Psychiatric Assistant"** — `psychnurse_npc` — `city/hospital.cpp:1181`
- **"Talk To Tin Foil Hat Man"** — `softroom_npc` — `city/hospital.cpp:1256`
- **"Talk To Time Traveler"** — `softroom_npc` — `city/hospital.cpp:1310`
- **"Talk To Hospital Director"** — `softroom_npc` — `city/hospital.cpp:1364`
- **"Talk To Maternity Nurse"** — `maternitynurse_npc` — `city/hospital.cpp:1432`
- **"Talk To Baby Nurse"** — `babynurse_npc` — `city/hospital.cpp:1552`
- **"Communicate Telepathically"** — `deadalien_npc` — `city/hospital.cpp:1642`
- **"Call Forth The Spirits"** — `corpse_npc` — `city/hospital.cpp:1663`
- **"Talk To Mad Scientist"** — `morguedoc_npc` — `city/hospital.cpp:1707`

### Hotel — `CITYHotelEntrance` (9 stubs)
- **"Talk To Hotel Clerk"** — `hotelclerk1_npc` — `city/hotel.cpp:84`
- **"Talk To Hotel Clerk"** — `hotelclerk2_npc` — `city/hotel.cpp:116`
- **"Talk To Hotel Clerk"** — `hotelclerk3_npc` — `city/hotel.cpp:148`
- **"Talk To Hotel Clerk"** — `hotelclerk4_npc` — `city/hotel.cpp:180`
- **"Talk To Bellhop"** — `bellhop_npc` — `city/hotel.cpp:222`
- **"Talk To Esteemed Patron"** — `couchperson1_npc` — `city/hotel.cpp:257`
- **"Talk To Honored Guest"** — `couchperson2_npc` — `city/hotel.cpp:289`
- **"Talk To Lifeguard"** — `lifeguard_npc` — `city/hotel.cpp:372`
- **"Talk To Maid"** — `maid_npc` — `city/hotel.cpp:798`

### Hourlymotel — `CITYHourlyMotel` (1 stub)
- **"Talk To Motel Guy"** — `motelclerk_npc` — `city/hourlymotel.cpp:63`

### Laundromat — `CITYLaundromat` (1 stub)
- **"Talk To Attendant"** — `laundromatowner_npc` — `city/laundromat.cpp:50`

### Museum — `CITYMuseumLobby` (5 stubs)
- **"Buy Art Exhibit Pass"** — `museumclerk_npc` — `city/museum.cpp:66`
- **"Talk To Museum Clerk"** — `museumclerk2_npc` — `city/museum.cpp:98`
- **"Show Art Exhibit Pass"** — `museumticketguy_npc` — `city/museum.cpp:137`
- **"Look At Gigantic Jewel"** — `PLAYER_npc` — `city/museum.cpp:516`
- **"Talk To Gift Shop Clerk"** — `giftshopclerk_npc` — `city/museum.cpp:602`

### Office — `CITYOfficeEntrance` (3 stubs)
- **"Talk To Office Lady"** — `officelady_npc` — Bob's note: *"TODO: make appointment for upstairs"* — `city/office.cpp:52`
- **"Read Plaque"** — `PLAYER_npc` — Bob's note: *"TODO: guy talking to people at couch"* — `city/office.cpp:92`
- **"Talk To Office Lady"** — `officelady_npc` — `city/office.cpp:351`

### Partystore — `CITYPartyStore` (5 stubs)
- **"Purchase Vice"** — `partystoreclerk_npc` — Bob's note: *"TODO: choose between hot dogs, cigarettes, beer, liquor, lottery tickets..."* — `city/partystore.cpp:48`
- **"Talk To Pharmacist"** — `pharmacist_npc` — Bob's note: *"TODO: buy ???"* — `city/partystore.cpp:68`
- **"Look In Cooler"** — `PLAYER_npc` — `city/partystore.cpp:76`
- **"Use ATM"** — `PLAYER_npc` — `city/partystore.cpp:82`
- **"Look In Toilet"** — `PLAYER_npc` — `city/partystore.cpp:122`

### Pawnshop — `CITYPawnShop` (1 stub)
- **"Talk To Pawn Shop Guy"** — `pawnshopguy_npc` — `city/pawnshop.cpp:65`

### Policestation — `CITYPoliceStationLobby` (9 stubs)
- **"Submit To Authority"** — `lobbycop_npc` — `city/policestation.cpp:108`
- **"Talk To Sheriff"** — `chief_npc` — `city/policestation.cpp:231`
- **"Talk To Sheriff"** — `interrogator_npc` — `city/policestation.cpp:297`
- **"Confess! Admit It, Punk!"** — `PLAYER_npc` — `city/policestation.cpp:324`
- **"Talk To Spook"** — `cia_npc` — `city/policestation.cpp:383`
- **"Talk To Officer"** — `holdingcop_npc` — `city/policestation.cpp:585`
- **"Call Officer"** — `visitingguard_npc` — `city/policestation.cpp:696`
- **"Talk To Guard"** — `guard_npc` — `city/policestation.cpp:864`
- **"Talk To Guard"** — `guard2_npc` — `city/policestation.cpp:907`

### Poolhall — `CITYPoolHall` (1 stub)
- **"Talk To Attendant"** — `poolattendant_npc` — `city/poolhall.cpp:49`

### Restaurant — `CITYFancyRestaurantEntrance` (3 stubs)
- **"Talk To Host"** — `host_npc` — `city/restaurant.cpp:54`
- **"Pay Bill"** — `checkout_npc` — `city/restaurant.cpp:76`
- **"Talk To Barbara"** — `frozenman_npc` — `city/restaurant.cpp:538`

### Stadium — `CITYStadiumBathroomLeftMens` (17 stubs)
- **"Talk To Pooping Man"** — `stallman1_npc` — `city/stadium.cpp:562`
- **"Talk To Pooping Man"** — `stallman2_npc` — `city/stadium.cpp:591`
- **"Talk To Pooping Man"** — `stallman3_npc` — `city/stadium.cpp:620`
- **"Talk To Pooping Man"** — `stallman4_npc` — `city/stadium.cpp:649`
- **"Talk To Checking Make-Up Woman"** — `stallwoman1_npc` — `city/stadium.cpp:721`
- **"Talk To Be Right Back Woman"** — `stallwoman2_npc` — `city/stadium.cpp:750`
- **"Talk To Freshening Up Woman"** — `stallwoman3_npc` — `city/stadium.cpp:779`
- **"Talk To Stepping Outside Woman"** — `stallwoman4_npc` — `city/stadium.cpp:808`
- **"Talk To Powdering Nose Woman"** — `stallwoman5_npc` — `city/stadium.cpp:837`
- **"Talk To Crew Guy"** — `crewguy1_npc` — `city/stadium.cpp:1009`
- **"Talk To Crew Guy"** — `crewguy2_npc` — `city/stadium.cpp:1045`
- **"Talk To Crew Guy"** — `city/stadium.cpp:1444`
- **"Talk To Producer"** — `producer_npc` — `city/stadium.cpp:1710`
- **"Talk To Editing Guy"** — `editingguy1_npc` — `city/stadium.cpp:1741`
- **"Talk To Editing Guy"** — `editingguy2_npc` — `city/stadium.cpp:1768`
- **"Talk To Rich Nerd Guy"** — `famousguy_npc` — `city/stadium.cpp:1899`
- **"Talk To Assistant"** — `assistant_npc` — `city/stadium.cpp:1929`

### Thecafe — `CITYTheCafeDressingRoom` (3 stubs)
- **"Talk To Dancer"** — `stripper1_npc` — `city/thecafe.cpp:309`
- **"Talk To Dancer"** — `stripper2_npc` — `city/thecafe.cpp:330`
- **"Talk To Dancer"** — `stripper3_npc` — `city/thecafe.cpp:351`

## Other

### Japanhouse — `JAPANUpstairsMainBedroom` (1 stub)
- **"Talk To Japanese Boy"** — `japanesekid_npc` — `other/japanhouse.cpp:45`

---
*Excluded from this catalog: 4 copy-paste template examples in `src/gamelogic/logicmethods.h` ("Look At THING" / "Talk To NAME" — Bob's cookbook, not real NPCs) and 2 commented-out blocks.*
*To fill one in: replace the `""` in the `TEXT_window("")` call with dialogue text. Keep Bob's TODO comment until the interaction is actually implemented.*
