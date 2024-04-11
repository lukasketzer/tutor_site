<script>
    import Entry from "$lib/Entry.svelte";
    import folie_woche1 from "$lib/lessons/week1/test.txt";
    const lessons = [];
</script>

<svelte:head>
    <title>Folien</title>
</svelte:head>

<div class="container">
    <div style="margin-top: 5em; margin-bottom: 5em">
        <h1 class="title is-1" style="text-align: center;">
            Grundlagen: Rechenarchitektur
        </h1>
        <h1 class="subtitle is-3" style="text-align: center;">
            Sommersemester 2024 | Lukas Ketzer
        </h1>
    </div>

    <div id="entries">
        {#if lessons.length == 0}
        No entries yet
        {:else}
            {#each lessons as lesson}
                <Entry week={lesson.week} files={lesson.files} />
            {/each}
        {/if}
    </div>
</div>

<style>
    #entries {
        display: flex;
        align-items: center;
        justify-content: center;
        flex-direction: column;
    }
</style>
