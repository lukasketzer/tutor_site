<script>
    import Entry from "$lib/Entry.svelte";
    import folie_woche1 from "$lib/franzisco/lessons/week1/test.txt";
    const lessons = [
        {
            week: 1,
            files: [
                {
                    url: folie_woche1,
                    text: "Folien",
                },
            ],
        },
    ];
    // const lessons = [];
</script>

<div class="entries">
    <div class="box" style="width: 70%">
        <h1 class="title is-size-5-mobile">Nützliche Links</h1>
        <hr />
        
        <a
            href="https://www.felixcloutier.com/x86/"
            class="button is-outlined is-warning  is-inverted "
        >
            x86 instructions
        </a>
        <a
            href="https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html#"
            class="button is-outlined is-warning  is-inverted "
        >
            Intel intrinsic
        </a>
        <a
            href="https://githowto.com/"
            class="button is-outlined is-warning  is-inverted "
        >
            GitHowTo
        </a>
        <a
            href="https://www.cit.tum.de/ito/fuer-studierende/fuer-neue/"
            class="button is-outlined is-warning  is-inverted "
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
