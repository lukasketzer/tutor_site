<script>
    import Entry from "$lib/Entry.svelte";
    import folie_woche1 from "$lib/lukas/lessons/week1/GRA_SS24_Week1.pdf";
    import example_woche1 from "$lib/lukas/lessons/week1/example.zip";

    import folie_woche2 from "$lib/lukas/lessons/week2/GRA_SS24_Week2.pdf";
    import example_woche2 from "$lib/lukas/lessons/week2/gra24getopt.zip";


    import makefile from "$lib/lukas/lessons/week5/Makefile.zip";
    import example_woche5 from "$lib/lukas/lessons/week5/Beispiel.zip";


    const lessons = [
        {
            week: 2,
            files: [
                {
                    url: folie_woche1,
                    text: "Folien",
                },
                {
                    url: example_woche1,
                    text: "Beispiele (Stack, Heap)"
                },
            ]
        },
        {
            week: 3,
            files: [
                {
                    url: folie_woche2,
                    text: "Folien",
                },
                {
                    url: example_woche2,
                    text: "getopt Lösung"
                },
            ],
        },
        {
            week: 5,
            files: [
                {
                    url: makefile,
                    text: "Makefile (MacOS / Linux)",
                },
                {
                    url: example_woche5,
                    text: "Beispiele (Referenzen, Constructor Member List)",
                },
            ],
        }
    ];
</script>


<div class="entries">
    <div class="box" style="width: 70%;">
        <h1 class="title is-size-5-mobile">Zeiten</h1>
        <ul>
            <li class="is-size-5">Gruppe 18: Do. 10:15 - 12:00 <span><a href="https://nav.tum.de/room/5608.EG.059">MI: 00.08.059</a></span></li>
            <li class="is-size-5">Gruppe 25: Do. 16:15 - 18:00 <span><a href="https://nav.tum.de/room/5606.01.011">MI: 01.06.011</a></span></li>
        </ul>
    </div>
    <div class="box" style="width: 70%">
        <h1 class="title is-size-5-mobile">Nützliche Links</h1>
        <hr />
        
        <a
            href="https://www.felixcloutier.com/x86/"
            class="button is-outlined is-warning is-inverted"
        >
            x86 instructions
        </a>
        <a
            href="https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html#"
            class="button  is-warning  is-inverted is-outlined "
        >
            Intel intrinsic
        </a>
        <a
            href="https://githowto.com/"
            class="button  is-warning  is-inverted is-outlined "
        >
            GitHowTo
        </a>
        <a
            href="https://www.cit.tum.de/ito/fuer-studierende/fuer-neue/"
            class="button  is-warning  is-inverted is-outlined "
        >
            ITO-Wiki: Für Neue
        </a>
    </div>

    {#if lessons.length == 0}
        <div class="block">No entries yet</div>
    {:else}
        {#each lessons as lesson}
            <Entry week={lesson.week} files={lesson.files} />
        {/each}
    {/if}
</div>

<style>
    .entries {
        display: flex;
        align-items: center;
        justify-content: center;
        flex-direction: column;
    }
    a {
        margin: 0.2rem;
    } 
</style>
